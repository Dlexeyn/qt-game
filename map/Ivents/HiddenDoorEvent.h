#ifndef HIDDENDOOREVENT_H
#define HIDDENDOOREVENT_H

#include "CellEvent.h"
#include "map/Cell.h"

class DeleteObjectEvent : public CellEvent
{
public:
    DeleteObjectEvent(Cell *newCell = nullptr) : CellEvent(newCell){}
    void trigger();
};

#endif // HIDDENDOOREVENT_H
