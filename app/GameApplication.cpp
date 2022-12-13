#include "GameApplication.h"
#include "map/Memento/Snapshot.h"

GameApplication::GameApplication(QApplication *app, QObject *parent)
    : QObject(parent),
      app(app)
{
    config = new Config::AppConfigurator(); // Настройки игры
    keyReader = new CommandReader();        // Класс, получающий клавиши управления
    logPool = new LogPool(config);          // Логи
    changeConfigs();

    keyReader->subscribe(logPool->getLoggers());
    keyReader->readCommands();

    careTaker = new CareTaker(recreate(), logPool->getLoggers());

    controller = new Controller(keyReader->getData()); // Класс, отвечающий за команды от пользователя
    levelWindow = new DialogLevel(config);  // Окно меню
    baseWindow = new BaseWindow(config);    // Окно уровня
    baseWindow->createDialogs(keyReader->getData());
    baseWindow->subscribe(logPool->getLoggers());

    connect(levelWindow, SIGNAL(changeLevel(int)), this, SLOT(setLevel(int)));
    connect(levelWindow, SIGNAL(changeSettings()), this, SLOT(changeConfigs()));
    connect(&gameTimer, SIGNAL(timeout()), this, SLOT(changeLevel()));
    connect(levelWindow, SIGNAL(endApp()), this, SLOT(exit()));
    connect(baseWindow, SIGNAL(endApp()), this, SLOT(exit()));
    connect(baseWindow, SIGNAL(endStatus(WindowStatus)), this, SLOT(continueGame(WindowStatus)));

    baseWindow->notifySubscribers("Starting the application", "global");
    delete keyReader;
}

GameApplication::~GameApplication()
{
    delete config;
    delete levelWindow;
    delete logPool;
    delete baseWindow;
}

void GameApplication::start()
{
    connect(levelWindow, &QDialog::rejected, levelWindow, &DialogLevel::on_exitButton_clicked);
    levelWindow->show();
}

void GameApplication::callStateDialogs(WindowStatus status)
{
    if(status == WindowStatus::GAME)
        return;
    gameTimer.stop();
    switch (status) {
    case WindowStatus::PAUSE:
        baseWindow->callPauseDialog();
        break;
    case WindowStatus::MENU:
        baseWindow->callMenuDialog();
        break;
    case WindowStatus::isSAVE:
        careTaker->backup(level);
        // Добавить диалог в случае не сохранения
        baseWindow->callSaveDialog();
        break;
    case WindowStatus::isLOAD:
        curIndexBackup = baseWindow->callLoadSaveDialog(careTaker->getInfo());
        break;
    case WindowStatus::isEXIT:
        baseWindow->callExitDialog();
        break;
    case WindowStatus::isRestart:
        baseWindow->callRestartEventDialog();
    default:
        break;
    }
}

void GameApplication::callStateFunction(WindowStatus status)
{
    switch (status) {
    case WindowStatus::END_LEVEL:
        gameTimer.stop();
        baseWindow->hide();
        careTaker->unsetOriginator();
        delete game;
        delete scene;
        levelWindow->show();
        break;
    case WindowStatus::RESTART_LEVEL:
        gameTimer.stop();
        baseWindow->hide();
        careTaker->unsetOriginator();

        delete game;
        delete scene;

        setLevel(this->level);
        break;
    case WindowStatus::LOAD_SAVE:
        gameTimer.stop();
        baseWindow->hide();

        careTaker->unsetOriginator();

        if(backUp)
            delete backUp;

        backUp = new Field;
        careTaker->setOriginator(backUp);

        level = careTaker->undo(curIndexBackup);

        delete game;
        delete scene;

        isSaveLoad = true;
        setLevel(level);
        break;
    case WindowStatus::DELETE_SAVE:
        careTaker->deleteBackup(abs(curIndexBackup));
        baseWindow->setStatus(WindowStatus::isLOAD);
        break;
    default:
        break;
    }
}

void GameApplication::setLevel(int level)
{
    this->level = level;
    disconnect(levelWindow, &QDialog::rejected, levelWindow, &DialogLevel::on_exitButton_clicked);
    levelWindow->hide();
    changeConfigs();

    scene = new QGraphicsScene();
    if(!isSaveLoad)
        game = new Game(logPool->getLoggers(), level, scene);
    else
        game = new Game(logPool->getLoggers(), level, backUp, scene);

    isSaveLoad = false;
    if(!game->field->getIsGenerated())
    {
        levelWindow->show();
        return;
    }

    game->initGame(baseWindow, controller, config);
    int hPx = game->field->getMap_height() * game->fView->getSizeCell();
    int wPx = game->field->getMap_width() * game->fView->getSizeCell();
    baseWindow->init(hPx, wPx, scene, game->field->getPlayer());
    baseWindow->setMediator(game);
    controller->setMediator(game);

    baseWindow->show();
    careTaker->setOriginator(game->field);
    gameTimer.start(150);
}

void GameApplication::changeConfigs()
{
    logPool->getLogManager()->initDecorators();
}

void GameApplication::changeLevel()
{
    baseWindow->slotPlayerTimer();
    callStateDialogs(baseWindow->getStatus());
    callStateFunction(baseWindow->getStatus());
}

void GameApplication::continueGame(WindowStatus curStatus)
{
    baseWindow->setStatus(curStatus);
    baseWindow->notifySubscribers("Status was ended", "global");
    baseWindow->setFocus();
    gameTimer.start(150);
}

std::vector<Memento *> GameApplication::recreate()
{
    std::vector<Memento*> rec;
    for(int i = 0; i < CareTaker::getSIZE(); i++)
    {
        Snapshot *s = new Snapshot(logPool->getLoggers());
        if(s->readFromFile(i))
        {
            rec.push_back(s);
        }
        else
            return rec;
    }
    return rec;
}

void GameApplication::exit()
{
    careTaker->saveToFile();
    baseWindow->notifySubscribers("Completing the application", "global");
    app->exit(0);
}
