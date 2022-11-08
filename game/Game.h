#ifndef GAME_H
#define GAME_H

#include <vector>
#include "GlobalMediator.h"
#include "GlobalComponent.h"
#include "config/AppConfigurator.h"
#include "map/ReadData.h"
#include "map/GameMediator.h"
#include "map/Ivents/GlobalEventFactory.h"
#include "log/LogObject.h"
#include "graphics/MapView.h"

class Game: public GlobalMediator, public LogObject
{
public:
    Game(ReadData* readData, const std::vector< Log::EventSubscriber* >& loggers, const int level);
    ~Game();
    void notify(GLMessage *mes);
    void initGame(EventWindow *window, GlobalComponent *controller, QGraphicsScene *scene, Config::AppConfigurator *config);
    void setReadData(ReadData *newReadData);
    View *getPlayerView() const;

private:
    View *isBox(int x, int y);
    void movement(int stepX, int stepY, int &x, int &y);
    bool boxMove(View *box, int stepX, int stepY);
    void createEvents();
    void addObjectsOnScene(QGraphicsScene *scene);

    int numBox;

    EventWindow *baseWindow = nullptr;
    GlobalComponent *controller = nullptr;
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
