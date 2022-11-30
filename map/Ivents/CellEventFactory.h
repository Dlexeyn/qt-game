#ifndef CELLEVENTFACTORY_H
#define CELLEVENTFACTORY_H


#include "EventFactory.h"
#include "map/objects/Player.h"
#include "map/Cell.h"
#include <vector>

enum CellEventType
{
    RETURN_COLOR,
    COLOR_BOX,
    HIDDEN_DOOR,
    DESTROY_PLAYER,
    NONE
};

class CellEventFactory : public EventFactory
{
public:
    CellEventFactory(CellEventType type, const std::vector<EventSubscriber*> &loggers, Player *p)
        : currentType(type), loggers(loggers), player(p){}
    CellEventFactory(const CellEventFactory& otherFactory);
    CellEventFactory(CellEventFactory&& otherFactory);
    ~CellEventFactory() {}
    Event* createEvent();
    void setCurrentType(CellEventType newCurrentType, CellSpace::Cell *object);

    void setPlayer(Player *newPlayer);

private:
    CellEventType currentType;
    std::vector<EventSubscriber*> loggers;
    CellSpace::Cell *object = nullptr;
    Player *player = nullptr;
};

#endif // CELLEVENTFACTORY_H
