#ifndef OBJECTEVENT_H
#define OBJECTEVENT_H

#include "Event.h"
#include "map/MapObject.h"
#include "map/Cell.h"
#include "map/Box.h"
#include "map/Field.h"



class ObjectEvent: public Event
{
public:
    ObjectEvent(MapObject *object = nullptr) : object(object){}

    void setObject(MapObject *newObject);

protected:
    MapObject *object = nullptr;
};






#endif // OBJECTEVENT_H
