#include "ReturnColorEvent.h"

void ReturnColorEvent::trigger()
{
    cell->setCell_type(CellSpace::TARGET_BOX);
    notifySubscribers("the \"ReturnColorBox\" event triggered", "event");
}
