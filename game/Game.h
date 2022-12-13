#ifndef GAME_H
#define GAME_H

#include <vector>
#include "GlobalMediator.h"
#include "GlobalComponent.h"
#include "config/AppConfigurator.h"
#include "graphics/FieldView.h"
#include "map/Ivents/GlobalEventFactory.h"
#include "log/LogObject.h"
#include "map/MapGenerator.h"

using namespace map;
class Game: public GlobalMediator, public LogObject
{
public:
    Game(const std::vector< Log::EventSubscriber* >& loggers,
         const int level, QGraphicsScene *scene);

    Game(const std::vector< Log::EventSubscriber* >& loggers,
         const int level, Field* field, QGraphicsScene *scene);

    ~Game();
    void notify(GLMessage *mes);
    void initGame(EventWindow *window, GlobalComponent *controller, Config::AppConfigurator *config);

private:
    void createEvents();
    void checkGameStatus();

    EventWindow *baseWindow = nullptr;
    GlobalComponent *controller = nullptr;

    GlobalEventFactory *globalEventFactory = nullptr;

    Event *victoryEvent = nullptr;
    Event *loseEvent = nullptr;

    Field *field = nullptr;
    FieldView *fView = nullptr;
    friend class GameApplication;

};

#endif // GAME_H
