#include "CellEvent.h"

CellEvent::CellEvent(EventSubscriber *logger, Cell *newCell) : cell(newCell)
{
    subscribe(logger, "obj");
}

void CellEvent::setCell(Cell *newCell)
{
    cell = newCell;
}


