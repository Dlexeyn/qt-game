#include "HiddenDoorEvent.h"

DeleteObjectEvent::DeleteObjectEvent()
{

}

void DeleteObjectEvent::trigger()
{
    (dynamic_cast<CellSpace::Cell*>(object))->setNext_cell_type(CellSpace::GRASS);
    (dynamic_cast<CellSpace::Cell*>(object))->changeStatus();
}
