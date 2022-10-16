#include "Cell.h"

namespace CellSpace {

void Cell::sendCignal(int type)
{
    switch (type) {
    case BOX_EVENT:
        if(cell_type == TARGET_BOX)
        {
            event->trigger();
            eventMediator->notify(this, "returnColor");
        }
        else if(cell_type == TARGET_WITH_BOX)
        {
            event->trigger();
            eventMediator->notify(this, "colorBox");
        }
        else if(cell_type == TEMP_WALL)
        {
            eventMediator->notify(this, "isOpenSublevel");
        }
        break;
    case RANDOM_EVENT:
        event->trigger();
        break;
    case GET_EVENT:
        if(cell_type == END_CELL)
            eventMediator->notify(this, "destroyPlayer");
        break;
    case CONDITION_IS_TRUE:
        if(cell_type == TEMP_WALL)
        {
            event->trigger();
            delete event;
            event = nullptr;
        }
        break;
    default:
        break;
    }
}

int Cell::getFirstAttribute() const
{
    return cell_type;
}

int Cell::getSecondAttribute() const
{
    return next_cell_type;
}

void Cell::setFirstAttribute(int newAttribute)
{
    cell_type = TypeOfCell(newAttribute);
}

void Cell::setSecondAttribute(int newAttribute)
{
    next_cell_type = TypeOfCell(newAttribute);
}

void Cell::changeStatus()
{
    if(cell_type == WALL and (next_cell_type == BROKEN_WALL or next_cell_type == GRASS))
        isPassable = true;

    cell_type = next_cell_type;
    next_cell_type = EMPTY;
}

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

void Cell::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}

void Cell::setNext_cell_type(TypeOfCell newNext_cell_type)
{
    next_cell_type = newNext_cell_type;
}

Player *Cell::getPlayer() const
{
    return player;
}
}
