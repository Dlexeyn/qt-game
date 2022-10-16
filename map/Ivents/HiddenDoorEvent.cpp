#include "HiddenDoorEvent.h"

void DeleteObjectEvent::trigger()
{
    object->setSecondAttribute(CellSpace::GRASS);
    object->changeStatus();
}
