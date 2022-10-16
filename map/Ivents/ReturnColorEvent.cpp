#include "ReturnColorEvent.h"

void ReturnColorEvent::trigger()
{
    object->setSecondAttribute(CellSpace::TARGET_BOX);
    object->changeStatus();
}
