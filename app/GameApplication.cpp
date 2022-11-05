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

    controller = new Controller(keyReader->getDataForController()); // Класс, отвечающий за команды от пользователя
    levelWindow = new DialogLevel(config);  // Окно меню
    baseWindow = new BaseWindow(config);    // Окно уровня
    baseWindow->createDialogs(keyReader->getDataForDialogs());
    baseWindow->subscribe(logPool->getLoggers());

    connect(levelWindow, SIGNAL(changeLevel(int)), this, SLOT(setLevel(int)));
    connect(levelWindow, SIGNAL(changeSettings()), this, SLOT(changeConfigs()));
    connect(&gameTimer, SIGNAL(timeout()), this, SLOT(changeLevel()));
    connect(levelWindow, SIGNAL(endApp()), this, SLOT(exit()));
    connect(baseWindow, SIGNAL(endApp()), this, SLOT(exit()));
    connect(baseWindow, SIGNAL(endStatus()), this, SLOT(continueGame()));

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

void GameApplication::callStateFunction(WindowStatus status)
{
    if(status == WindowStatus::GAME)
        return;
    gameTimer.stop();
    switch (status) {
    case WindowStatus::PAUSE:
        baseWindow->callPauseDialog();
        break;
    case WindowStatus::MENU:
        baseWindow->callMenuDialog();           // menu class
        break;
//    case WindowStatus::NEW_GAME:
//        baseWindow->callNewGameDialog();        // restart level
//        break;
//    case WindowStatus::SAVE:
//        baseWindow->callSaveDialog();           // save level into txt
//        break;
    case WindowStatus::EXIT:
        baseWindow->callExitDialog();
        break;
    default:
        break;
    }
}

void GameApplication::setLevel(int level)
{
    disconnect(levelWindow, &QDialog::rejected, levelWindow, &DialogLevel::on_exitButton_clicked);
    levelWindow->hide();
    changeConfigs();

    scene = new QGraphicsScene();
    lvlReader = new LevelReader(level);

    game = new Game(lvlReader->getReadData(), logPool->getLoggers(), level);
    game->initGame(baseWindow, controller, scene);

    baseWindow->init(lvlReader->getReadData(), scene, game->getPlayerView());
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
    callStateFunction(baseWindow->getStatus());

    if(baseWindow->getEnd())
    {
        baseWindow->setEnd(false);
        gameTimer.stop();
        baseWindow->hide();
        delete game;
        delete scene;
        levelWindow->show();
    }
}

void GameApplication::continueGame()
{
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
