#include "Game.h"
#include "map/Field.h"
#include "graphics/FieldView.h"
#include "graphics/PlayerView.h"

Game::Game(ReadData *readData, const std::vector<EventSubscriber *> &loggers,
           const int level, QGraphicsScene *scene)
    : readData(readData)
{
    subscribe(loggers);
    notifySubscribers("Level ", "global", new LogArgs(ArgsLog::LEVEL, level));
    field = new Field(readData, loggers);                                           // реализация поля
    fView = new FieldView(field, readData, scene);                                  // абстракция поля
}

Game::~Game()
{
    notifySubscribers("Level completed", "global");
    notifySubscribers("Deleting objects", "object");
    delete globalEventFactory;
    delete victoryEvent;
    delete loseEvent;
}

void Game::notify(GLMessage *mes)
{
    switch(mes->getSender())
    {
    case Sender::CONTROLLER_PLAYER:
        field->movement(mes->getArg(ArgsTypes::X),
                mes->getArg(ArgsTypes::Y));
        checkGameStatus();
        break;
    case Sender::CONTROLLER_GAME:
        baseWindow->getMessage(mes);
        break;
    case Sender::WINDOW:
        controller->getMessage(mes);
        break;
    default:
        break;
    }
}

void Game::initGame(EventWindow *window, GlobalComponent *controller, Config::AppConfigurator *config)
{
    baseWindow = window;
    this->controller = controller;

    globalEventFactory = new GlobalEventFactory(GlobalEventFactory::Victory, baseWindow);
    victoryEvent = globalEventFactory->createEvent();

    if(config->getGameOption("lose_restart"))
        globalEventFactory->setCurrentType(GlobalEventFactory::Restart);
    else
        globalEventFactory->setCurrentType(GlobalEventFactory::Lose);
    loseEvent = globalEventFactory->createEvent();

    notifySubscribers("The game has started", "game");
}

void Game::setReadData(ReadData *newReadData)
{
    readData = newReadData;
}

void Game::createEvents()
{
    globalEventFactory = new GlobalEventFactory(GlobalEventFactory::Victory, baseWindow);
    victoryEvent = globalEventFactory->createEvent();

    globalEventFactory->setCurrentType(GlobalEventFactory::Lose);
    loseEvent = globalEventFactory->createEvent();
}

void Game::checkGameStatus()
{
    if(field->getPlayer()->getCurHealth() == 0)
        loseEvent->trigger();
    else if(field->getPlayer()->getVictoryPoints() == readData->getConditionVictory())
        victoryEvent->trigger();
}


