#ifndef SUBLEVELDOORRULE_H
#define SUBLEVELDOORRULE_H
#include "Field.h"
#include "map/GeneratorError.h"

template <int x, int y>
class SubLevelDoorRule
{
public:
    SubLevelDoorRule() {}
    void fill(map::Field &field)
    {
        if(x >= field.getMap_width() or y >= field.getMap_height()
                        or x < 0 or y < 0)
            throw errors::GeneratorError(errors::Gen_Errors::OUT_OF_BOUNDS_DOORS);
        field.setHidDoor(new QPoint(x, y));
        Cell *cell = field.getMap_field()[y][x];
        field.getEventFactory()->setCurrentType(CellEventType::HIDDEN_DOOR, cell);
        cell->setCell_type(CellSpace::TEMP_WALL);
        cell->setEvent(field.getEventFactory()->createEvent());
    }
};

#endif // SUBLEVELDOORRULE_H
