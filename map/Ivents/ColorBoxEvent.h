#ifndef COLORBOXEVENT_H
#define COLORBOXEVENT_H

#include "CellEvent.h"
#include "map/Cell.h"

class ColorBoxEvent : public CellEvent
{
public:
    ColorBoxEvent(Cell *newCell = nullptr) : CellEvent(newCell){}
    void trigger();
};

#endif // COLORBOXEVENT_H
