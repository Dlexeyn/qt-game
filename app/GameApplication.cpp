#include "GameApplication.h"

GameApplication::GameApplication(QApplication *app, QObject *parent)
    : QObject(parent),
      app(app)
{
    config = new Config::AppConfigurator(); // Настройки игры
    levelWindow = new DialogLevel(config);  // Окно меню
    baseWindow = new BaseWindow(config);    // Окно уровня
    controller = new Controller();
    logPool = new LogPool(config);
    baseWindow->subscribe(logPool->getLoggers());
    connect(levelWindow, SIGNAL(changeLevel(int)), this, SLOT(setLevel(int)));
    connect(levelWindow, SIGNAL(changeSettings()), this, SLOT(changeConfigs()));
    connect(&gameTimer, SIGNAL(timeout()), this, SLOT(changeLevel()));
    connect(levelWindow, SIGNAL(endApp()), this, SLOT(exit()));
    connect(baseWindow, SIGNAL(endApp()), this, SLOT(exit()));
    changeConfigs();
    baseWindow->notifySubscribers("Starting the application", "global");
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
    //levelWindow->exec();
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

void GameApplication::exit()
{
    baseWindow->notifySubscribers("Completing the application", "global");
    app->exit(0);
}
