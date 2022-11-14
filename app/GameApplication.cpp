#include "GameApplication.h"

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
//    case WindowStatus::NEW_GAME:
//        baseWindow->callNewGameDialog();        // restart level
//        break;
//    case WindowStatus::SAVE:
//        baseWindow->callSaveDialog();           // save level into txt
//        break;
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
        delete game;
        delete scene;
        levelWindow->show();
        break;
    case WindowStatus::RESTART_LEVEL:
        gameTimer.stop();
        baseWindow->hide();
        delete game;
        delete scene;
        setLevel(this->level);
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
    lvlReader = new LevelReader(this->level);

    game = new Game(lvlReader->getReadData(), logPool->getLoggers(), level, scene);
    game->initGame(baseWindow, controller, config);

    baseWindow->init(lvlReader->getReadData(), scene, game->field->getPlayer());
    baseWindow->setMediator(game);
    controller->setMediator(game);

    baseWindow->show();
    gameTimer.start(150);

    delete lvlReader;
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
    if(int(curStatus))
        baseWindow->setStatus(WindowStatus::GAME);
    baseWindow->notifySubscribers("Status was ended", "global");
    baseWindow->setFocus();
    gameTimer.start(150);
}

void GameApplication::exit()
{
    baseWindow->notifySubscribers("Completing the application", "global");
    app->exit(0);
}
