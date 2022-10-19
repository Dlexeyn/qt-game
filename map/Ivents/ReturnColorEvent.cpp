#include "ReturnColorEvent.h"

void ReturnColorEvent::trigger()
{
    cell->setCell_type(CellSpace::TARGET_BOX);
//    object->setSecondAttribute(CellSpace::TARGET_BOX);
//    object->changeStatus();
}
