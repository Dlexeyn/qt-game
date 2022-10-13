#include "Game.h"

Game::Game(BaseWindow *baseWindow, Controller *controller, FieldScene *fieldScene, LevelReader *lvlReader)
    : baseWindow(baseWindow), controller(controller), fieldScene(fieldScene), lvlReader(lvlReader) {

    globalEventFactory = new GlobalEventFactory(GlobalEventFactory::Victory, baseWindow);
    victoryEvent = globalEventFactory->createEvent();

    globalEventFactory->setCurrentType(GlobalEventFactory::Lose);
    loseEvent = globalEventFactory->createEvent();
}

void Game::notify(GlobalComponent *sender, std::string mes)
{
    if(mes == "controller")
    {
        fieldScene->checkPlayerStep(controller->getStepX(), controller->getStepY());
    }
    else if(mes == "fieldScene")
    {
        if(fieldScene->getPlayerView()->getPoints() == lvlReader->getConditionVictory())
        {
            victoryEvent->trigger();
        }
        if(!fieldScene->getPlayerView()->getPlayer()->getIsAlive())
        {
            loseEvent->trigger();
        }
    }


}
