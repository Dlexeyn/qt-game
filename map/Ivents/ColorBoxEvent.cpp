#include "ColorBoxEvent.h"

ColorBoxEvent::ColorBoxEvent()
{

}

void ColorBoxEvent::trigger()
{
    (dynamic_cast<CellSpace::Cell*>(object))->setNext_cell_type(CellSpace::TARGET_WITH_BOX);
    (dynamic_cast<CellSpace::Cell*>(object))->changeStatus();
}
