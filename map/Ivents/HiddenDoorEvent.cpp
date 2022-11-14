#include "HiddenDoorEvent.h"

void DeleteObjectEvent::trigger()
{
    cell->setCell_type(GRASS);
    emit cell->typeChanged();
    cell->setIsPassable(true);
    notifySubscribers("the \"HiddenDoor\" event triggered", "event");
}
