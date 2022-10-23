#include "ReturnColorEvent.h"

void ReturnColorEvent::trigger()
{
    cell->setCell_type(CellSpace::TARGET_BOX);
    notifySubscriber("the \"ReturnColorBox\" event triggered");
}
