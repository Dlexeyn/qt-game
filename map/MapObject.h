#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "game/Mediator.h"

enum class ObjectAttribute{
    OBJECT,
    CUR_X,
    CUR_Y,
    HEALTH,
    POINTS
};

class MapObject
{
public:
    virtual int changeStatus() = 0;
    virtual void sendCignal() = 0;
    virtual void setEventMediator(Mediator *newEventMediator) = 0;
    virtual int getAttribute(ObjectAttribute at) const = 0;
    virtual void setAttribute(ObjectAttribute at, int arg) = 0;
    virtual void callAnObject() = 0;
    virtual bool checkState() = 0;

    //virtual ~MapObject() = default;
};

#endif // MAPOBJECT_H
