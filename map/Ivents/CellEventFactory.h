#ifndef CELLEVENTFACTORY_H
#define CELLEVENTFACTORY_H


#include "EventFactory.h"
#include "CellEvent.h"
#include "ReturnColorEvent.h"
#include "ColorBoxEvent.h"
#include "HiddenDoorEvent.h"


class CellEventFactory : public EventFactory
{
public:

    enum CellEventType
    {
        RETURN_COLOR,
        COLOR_BOX,
        HIDDEN_DOOR,
        DESTROY_PLAYER
    };

    CellEventFactory(CellEventType type, EventSubscriber *logger): currentType(type),
    logger(logger){}
    CellEventFactory(const CellEventFactory& otherFactory);
    CellEventFactory(CellEventFactory&& otherFactory);
    ~CellEventFactory() {}
    Event* createEvent();
    void setCurrentType(CellEventType newCurrentType, Cell *object);

private:
    CellEventType currentType;
    EventSubscriber *logger = nullptr;
    Cell *object = nullptr;
};

#endif // CELLEVENTFACTORY_H
