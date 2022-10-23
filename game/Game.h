#ifndef GAME_H
#define GAME_H

#include <vector>
#include "GlobalMediator.h"
#include "GlobalComponent.h"
#include "Controller.h"
#include "map/ReadData.h"
#include "graphics/basewindow.h"
#include "graphics/FieldView.h"
#include "graphics/MapView.h"
#include "map/LevelReader.h"
#include "map/Ivents/GlobalEventFactory.h"
#include "map/Box.h"
#include "map/Cell.h"
#include "map/Field.h"
#include "objects/Player.h"
#include "log/LogObject.h"

class Game: public GlobalMediator, public LogObject
{
public:
    Game(BaseWindow *baseWindow, Controller *controller, ReadData *readData);
    ~Game();
    void notify(std::string mes = "");
    void initGame(MapView *fieldView, View *playerView, std::vector<View *> &listBoxView, int numBox);

    void setReadData(ReadData *newReadData);

private:
    View *isBox(int x, int y);
    bool boxMove(View *box, int stepX, int stepY);
    void setCurPos(int addX = 0, int addY = 0);

    int numBox;

    BaseWindow *baseWindow = nullptr;
    Controller *controller = nullptr;
    ReadData *readData = nullptr;

    GlobalEventFactory *globalEventFactory = nullptr;

    Event *victoryEvent = nullptr;
    Event *loseEvent = nullptr;

    MapView *fieldView = nullptr;
    View *playerView = nullptr;
    std::vector<View*> listBoxView;
};

#endif // GAME_H
