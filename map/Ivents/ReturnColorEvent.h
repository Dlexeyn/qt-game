#ifndef RETURNCOLOREVENT_H
#define RETURNCOLOREVENT_H

#include "ObjectEvent.h"
#include "map/Cell.h"

class ReturnColorEvent : public ObjectEvent
{
public:
    ReturnColorEvent(MapObject *obj) : ObjectEvent(obj){}
    void trigger();
};

#endif // RETURNCOLOREVENT_H
