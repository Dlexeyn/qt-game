#include "HiddenDoorEvent.h"

void DeleteObjectEvent::trigger()
{
    cell->setCell_type(GRASS);
    cell->setIsPassable(true);
}
