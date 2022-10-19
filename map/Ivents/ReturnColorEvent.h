#ifndef RETURNCOLOREVENT_H
#define RETURNCOLOREVENT_H

#include "CellEvent.h"
#include "map/Cell.h"

class ReturnColorEvent : public CellEvent
{
public:
    ReturnColorEvent(Cell *newCell = nullptr) : CellEvent(newCell){}
    void trigger();
};

#endif // RETURNCOLOREVENT_H
