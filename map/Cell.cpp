#include "Cell.h"

namespace CellSpace {

bool Cell::getIsPassable() const
{
    return isPassable;
}

void Cell::setIsPassable(bool newIsPassable)
{
    isPassable = newIsPassable;
}

TypeOfCell Cell::getCell_type() const
{
    return cell_type;
}

void Cell::clearEvent()
{
    delete event;
    event = nullptr;
}

Event *Cell::getEvent() const
{
    return event;
}

void Cell::setCell_type(TypeOfCell newCell_type)
{
    cell_type = newCell_type;
}

void Cell::setEvent(Event *newEvent)
{
    event = newEvent;
}
}
