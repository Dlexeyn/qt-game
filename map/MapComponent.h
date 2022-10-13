#ifndef MAPCOMPONENT_H
#define MAPCOMPONENT_H

#include "game/Mediator.h"
#include "map/MapObject.h"

class MapComponent: public MapObject
{
public:
    virtual void sendCignal(int type) = 0;

    void setEventMediator(Mediator *newEventMediator);

protected:
    Mediator *eventMediator = nullptr;
};

inline void MapComponent::setEventMediator(Mediator *newEventMediator)
{
    eventMediator = newEventMediator;
}

#endif // MAPCOMPONENT_H
