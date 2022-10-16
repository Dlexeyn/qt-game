#include "ColorBoxEvent.h"

void ColorBoxEvent::trigger()
{
    object->setSecondAttribute(CellSpace::TARGET_WITH_BOX);
    object->changeStatus();
}
