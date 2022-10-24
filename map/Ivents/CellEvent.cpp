#include "CellEvent.h"

CellEvent::CellEvent(const std::vector<EventSubscriber*> &loggers, Cell *newCell) : cell(newCell)
{
    subscribe(loggers);
}

void CellEvent::setCell(Cell *newCell)
{
    cell = newCell;
}


