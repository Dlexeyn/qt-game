#include "Game.h"
#include "map/BoxesRule.h"
#include "map/Field.h"
#include "graphics/FieldView.h"
#include "map/PlayerRule.h"
#include "map/WallRule.h"
#include "map/TrapRule.h"
#include "map/TargetRule.h"
#include "map/SubLevelDoorRule.h"
#include "map/ConditionsRule.h"

Game::Game(const std::vector<EventSubscriber *> &loggers,
           const int level, QGraphicsScene *scene)
{
    subscribe(loggers);
    notifySubscribers("Level ", "global", new LogArgs(ArgsLog::LEVEL, level));

    if(level == 1)
    {
        MapGenerator <WallRule<map::level::FIRST>,
                      PlayerRule<7, 3>,
                      BoxesRule<5, 2, 3, 4, 3, 6, 4, 7, 2, 11, 3>,
                      TrapRule<5, 5>,
                      TargetsRule<2, 4, 3, 4, 2, 5, 3, 5, 12, 3>,
                      SubLevelDoorRule <9, 3>,
                      ConditionsRule<5, 4>
                >mapGen;

        field = new Field(mapGen.generate(loggers));
    }
    else if(level == 2){
        MapGenerator <WallRule<map::level::SECOND>,
                      PlayerRule<11, 8>,
                      BoxesRule<6, 2, 7, 5, 7, 5, 4, 5, 2, 7, 3, 8, 4>,
                      TrapRule<6, 9>,
                      TargetsRule<18, 6, 19, 6, 18, 7, 19, 7, 18, 8, 19, 8>,
                      ConditionsRule<6, 0>
                >mapGen;

        field = new Field(mapGen.generate(loggers));
    }
    if(field->getIsGenerated())
    {
        field->subscribeInto(loggers);
        fView = new FieldView(field, scene);               // абстракция поля
    }
}

Game::Game(const std::vector<EventSubscriber *> &loggers,
           const int level,
           Field *field,
           QGraphicsScene *scene)
{
    subscribe(loggers);
    notifySubscribers("Level ", "global", new LogArgs(ArgsLog::LEVEL, level));

    this->field = field;
    field->subscribeInto(loggers);
    fView = new FieldView(field, scene);
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
        field->movement(mes->getArg(ArgsTypes::X),  // ref, field must extends GlobalComponent
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
    else if(field->getPlayer()->getVictoryPoints() >= field->getVictory())
        victoryEvent->trigger();
}


