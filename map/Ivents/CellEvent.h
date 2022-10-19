#ifndef CELLEVENT_H
#define CELLEVENT_H

#include "Event.h"
#include "map/Cell.h"

using namespace CellSpace;

class CellEvent: public Event
{
public:
    CellEvent(Cell *newCell = nullptr) : cell(newCell){}

    void setCell(Cell *newCell);

protected:
    Cell *cell = nullptr;
};






#endif // CELLEVENT_H
