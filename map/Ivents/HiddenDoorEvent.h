#ifndef HIDDENDOOREVENT_H
#define HIDDENDOOREVENT_H

#include "ObjectEvent.h"
#include "map/Cell.h"

class DeleteObjectEvent : public ObjectEvent
{
public:
    DeleteObjectEvent(MapObject *obj) : ObjectEvent(obj){}
    void trigger();
};

#endif // HIDDENDOOREVENT_H
