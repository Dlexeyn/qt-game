#include "ColorBoxEvent.h"

void ColorBoxEvent::trigger()
{
    cell->setCell_type(CellSpace::TARGET_WITH_BOX);
}
