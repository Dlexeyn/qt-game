#include "ReturnColorEvent.h"

ReturnColorEvent::ReturnColorEvent()
{

}

void ReturnColorEvent::trigger()
{
    (dynamic_cast<CellSpace::Cell*>(object))->setNext_cell_type(CellSpace::TARGET_BOX);
    (dynamic_cast<CellSpace::Cell*>(object))->changeStatus();
}
