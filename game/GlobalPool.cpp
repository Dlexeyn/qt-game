#include "GlobalPool.h"

GlobalPool::GlobalPool()
{
    scene = new QGraphicsScene();
    window = new BaseWindow();
    controller = new Controller();
    window->setController(controller);

    lvlReader = new LevelReader(window->getDialogLevel()->getLevel());

    game = new Game(window, controller, lvlReader->getReadData());
    game->setReadData(lvlReader->getReadData());
    window->setMediator(game);
    controller->setMediator(game);
    lvlReader->setMediator(game);
}

LevelReader *GlobalPool::getLvlReader() const
{
    return lvlReader;
}

void GlobalPool::startGame(MapView *fieldView, View *playerView, std::vector<View *> &listBoxView)
{
    game->initGame(fieldView, playerView, listBoxView, lvlReader->getReadData()->getNumBox());  // клиентский код
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
