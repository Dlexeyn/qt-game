#ifndef COLORBOXEVENT_H
#define COLORBOXEVENT_H

#include "CellEvent.h"
#include "map/Cell.h"

class ColorBoxEvent : public CellEvent
{
public:
    using CellEvent::CellEvent;
    void trigger();
};

#endif // COLORBOXEVENT_H
