#include "Cell.h"

namespace CellSpace {
void Cell::sendCignal(int type)
{
    switch (type) {
    case CURRENT_CELL:
        eventMediator->notify(this, "Cell");
        break;
    case 2:

    default:
        break;
    }
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

//int Cell::triggerForPlayer()
//{
//    int ret = 0;
//    switch (cell_type) {
//    case GRASS:
//        //player->regenHealth(5);
//        break;
//    case TRAP:
//        player->takeDamage(40);
//        next_cell_type = BROKEN_TRAP;
//        changeStatus();
//        ret = 1;
//        break;
//    default:
//        break;
//    }
//    return ret;
//}

void Cell::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}

void Cell::setNext_cell_type(TypeOfCell newNext_cell_type)
{
    next_cell_type = newNext_cell_type;
}
}
