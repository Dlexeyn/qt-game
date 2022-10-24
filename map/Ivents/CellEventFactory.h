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

    CellEventFactory(CellEventType type, const std::vector<EventSubscriber*> &loggers): currentType(type),
    loggers(loggers){}
    CellEventFactory(const CellEventFactory& otherFactory);
    CellEventFactory(CellEventFactory&& otherFactory);
    ~CellEventFactory() {}
    Event* createEvent();
    void setCurrentType(CellEventType newCurrentType, Cell *object);

private:
    CellEventType currentType;
    std::vector<EventSubscriber*> loggers;
    Cell *object = nullptr;
};

#endif // CELLEVENTFACTORY_H
