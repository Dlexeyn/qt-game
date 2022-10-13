#ifndef COLORBOXEVENT_H
#define COLORBOXEVENT_H

#include "ObjectEvent.h"

class ColorBoxEvent : public ObjectEvent
{
public:
    ColorBoxEvent();
    void trigger();
};

#endif // COLORBOXEVENT_H
