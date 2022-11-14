#ifndef GAME_H
#define GAME_H

#include <vector>
#include "GlobalMediator.h"
#include "GlobalComponent.h"
#include "config/AppConfigurator.h"
#include "graphics/FieldView.h"
#include "map/Field.h"
#include "map/ReadData.h"
#include "map/Ivents/GlobalEventFactory.h"
#include "log/LogObject.h"

class Game: public GlobalMediator, public LogObject
{
public:
    Game(ReadData* readData, const std::vector< Log::EventSubscriber* >& loggers,
         const int level, QGraphicsScene *scene);
    ~Game();
    void notify(GLMessage *mes);
    void initGame(EventWindow *window, GlobalComponent *controller, Config::AppConfigurator *config);
    void setReadData(ReadData *newReadData);

private:
    void createEvents();
    void checkGameStatus();
    int numBox;

    EventWindow *baseWindow = nullptr;
    GlobalComponent *controller = nullptr;
    ReadData *readData = nullptr;

    GlobalEventFactory *globalEventFactory = nullptr;

    Event *victoryEvent = nullptr;
    Event *loseEvent = nullptr;

    Field *field = nullptr;
    FieldView *fView = nullptr;
    friend class GameApplication;

};

#endif // GAME_H
