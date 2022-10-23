#include "HiddenDoorEvent.h"

void DeleteObjectEvent::trigger()
{
    cell->setCell_type(GRASS);
    cell->setIsPassable(true);
    notifySubscriber("the \"HiddenDoor\" event triggered");
}
