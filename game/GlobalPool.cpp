#include "GlobalPool.h"

GlobalPool::GlobalPool(LogPool *logPool)
{
    scene = new QGraphicsScene();
    window = new BaseWindow(logPool->getConfig());
    controller = new Controller();
    lvlReader = new LevelReader(window->getDialogLevel()->getLevel());
    game = new Game(window, controller, lvlReader->getReadData());

    game->setReadData(lvlReader->getReadData());
    window->setController(controller);  //?

    window->setMediator(game);
    controller->setMediator(game);
    lvlReader->setMediator(game);

    window->subscribe(logPool->getLoggers());
    game->subscribe(logPool->getLoggers());
}

LevelReader *GlobalPool::getLvlReader() const
{
    return lvlReader;
}

void GlobalPool::startGame(MapView *fieldView, View *playerView, std::vector<View *> &listBoxView)
{
    game->initGame(fieldView, playerView, listBoxView, lvlReader->getReadData()->getNumBox());
    game->notifySubscribers("Game : game was started", "state");
    window->init(lvlReader->getReadData(), scene, playerView);
}

QGraphicsScene *GlobalPool::getScene()
{
    return scene;
}

BaseWindow *GlobalPool::getWindow() const
{
    return window;
}
