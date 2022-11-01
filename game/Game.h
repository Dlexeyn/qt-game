#ifndef GAME_H
#define GAME_H

#include <vector>
#include "GlobalMediator.h"
#include "GlobalComponent.h"
#include "Controller.h"
#include "map/ReadData.h"
#include "map/GameMediator.h"
#include "graphics/basewindow.h"
#include "map/Ivents/GlobalEventFactory.h"
#include "log/LogObject.h"
#include "graphics/MapView.h"

class Game: public GlobalMediator, public LogObject
{
public:
    Game(ReadData* readData, const std::vector< Log::EventSubscriber* >& loggers, const int level);
    ~Game();
    void notify(GlobalComponent* sender, GLMessage *mes);
    void initGame(BaseWindow *window, Controller *controller, QGraphicsScene *scene);
    void setReadData(ReadData *newReadData);
    View *getPlayerView() const;

private:
    View *isBox(int x, int y);
    void movement(int x, int y, QPoint *posPlayer);
    bool boxMove(View *box, int stepX, int stepY);
    void setCurPos(int addX = 0, int addY = 0);
    void createEvents();
    void addObjectsOnScene(QGraphicsScene *scene);

    int numBox;

    BaseWindow *baseWindow = nullptr;
    Controller *controller = nullptr;
    ReadData *readData = nullptr;

    GlobalEventFactory *globalEventFactory = nullptr;

    Event *victoryEvent = nullptr;
    Event *loseEvent = nullptr;

    MapComponent *field = nullptr;
    MapComponent *player = nullptr;
    std::vector<MapComponent*> listBox;

    MapView *fieldView = nullptr;
    View *playerView = nullptr;
    std::vector<View*> listBoxView;

    GameMediator *objectMediator = nullptr;
};

#endif // GAME_H
