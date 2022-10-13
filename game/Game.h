#ifndef GAME_H
#define GAME_H

#include "GlobalMediator.h"
#include "GlobalComponent.h"
#include "Controller.h"
#include "graphics/basewindow.h"
#include "graphics/FieldScene.h"
#include "map/LevelReader.h"
#include "map/Ivents/GlobalEventFactory.h"

class Game: public GlobalMediator
{
public:
    Game(BaseWindow *baseWindow, Controller *controller, FieldScene *fieldScene, LevelReader *lvlReader);
    void notify(GlobalComponent *sender, std::string mes = "");

private:
    BaseWindow *baseWindow = nullptr;
    Controller *controller = nullptr;
    FieldScene *fieldScene = nullptr;
    LevelReader *lvlReader = nullptr;

    GlobalEventFactory *globalEventFactory = nullptr;

    Event *victoryEvent = nullptr;
    Event *loseEvent = nullptr;

};

#endif // GAME_H
