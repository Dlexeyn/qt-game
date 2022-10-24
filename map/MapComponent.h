#ifndef MAPCOMPONENT_H
#define MAPCOMPONENT_H

#include "game/Mediator.h"
#include "map/MapObject.h"
#include "log/LogObject.h"

class MapComponent: public MapObject, public LogObject
{
public:
    virtual ~MapComponent() = default;
    void setEventMediator(Mediator *newEventMediator);

protected:
    Mediator *eventMediator = nullptr;
};

inline void MapComponent::setEventMediator(Mediator *newEventMediator)
{
    eventMediator = newEventMediator;
}

#endif // MAPCOMPONENT_H
