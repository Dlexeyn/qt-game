#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "game/Mediator.h"

class MapObject
{
public:
    virtual void changeStatus() = 0;
    virtual void sendCignal(int type) = 0;
    virtual void setEventMediator(Mediator *newEventMediator) = 0;
    virtual int getFirstAttribute() const = 0;
    virtual int getSecondAttribute() const = 0;
    virtual void setFirstAttribute(int newAttribute) = 0;
    virtual void setSecondAttribute(int newAttribute) = 0;
    virtual ~MapObject() = default;
};

#endif // MAPOBJECT_H
