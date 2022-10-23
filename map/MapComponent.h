#ifndef MAPCOMPONENT_H
#define MAPCOMPONENT_H

#include "game/Mediator.h"
#include "map/MapObject.h"
#include "log/LogObject.h"

class MapComponent: public MapObject, public LogObject
{
public:
    //void setEvent(Event *newEvent);
    virtual ~MapComponent() = default;
    void setEventMediator(Mediator *newEventMediator);
    //Event *getEvent() const;

protected:
    Mediator *eventMediator = nullptr;
    //Event *event = nullptr;
};

inline void MapComponent::setEventMediator(Mediator *newEventMediator)
{
    eventMediator = newEventMediator;
}

//inline Event *MapComponent::getEvent() const
//{
//    return event;
//}

//inline void MapComponent::setEvent(Event *newEvent)
//{
//    event = newEvent;
//}

#endif // MAPCOMPONENT_H
