#ifndef COLORBOXEVENT_H
#define COLORBOXEVENT_H

#include "ObjectEvent.h"
#include "map/Cell.h"

class ColorBoxEvent : public ObjectEvent
{
public:
    ColorBoxEvent(MapObject *obj) : ObjectEvent(obj){}
    void trigger();
};

#endif // COLORBOXEVENT_H
