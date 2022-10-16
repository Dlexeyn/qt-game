#ifndef MAPCOMPONENT_H
#define MAPCOMPONENT_H

#include "game/Mediator.h"
#include "Ivents/ObjectEvent.h"

class MapComponent: public MapObject
{
public:
    void setEvent(Event *newEvent);
    void setEventMediator(Mediator *newEventMediator);
    Event *getEvent() const;

protected:
    Mediator *eventMediator = nullptr;
    Event *event = nullptr;
};

inline void MapComponent::setEventMediator(Mediator *newEventMediator)
{
    eventMediator = newEventMediator;
}

inline Event *MapComponent::getEvent() const
{
    return event;
}

inline void MapComponent::setEvent(Event *newEvent)
{
    event = newEvent;
}

#endif // MAPCOMPONENT_H
