#include "Cell.h"

void Cell::changeStatus()
{
    if(cell_type == WALL and next_cell_type == BROKEN_WALL)
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

Cell::TypeOfCell Cell::getCell_type() const
{
    return cell_type;
}

void Cell::triggerForPlayer(Player *player)
{
    switch (cell_type) {
    case GRASS:
        player->regenHealth(5);
        break;
    case LAVA:
        player->destruction();
        break;
    case TRAP:
        player->takeDamage(40);
        next_cell_type = BROKEN_TRAP;
        changeStatus();
        break;
    default:
        break;
    }
}
