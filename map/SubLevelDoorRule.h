#ifndef SUBLEVELDOORRULE_H
#define SUBLEVELDOORRULE_H
#include "Field.h"

template <int x, int y>
class SubLevelDoorRule
{
public:
    SubLevelDoorRule() {}
    std::string fill(map::Field &field)
    {
        if(x >= field.getMap_width() or y >= field.getMap_height()
                        or x < 0 or y < 0)
            return "going out of bounds in Door XY";
        field.setHidDoor(new QPoint(x, y));
        Cell *cell = field.getMap_field()[y][x];
        field.getEventFactory()->setCurrentType(CellEventType::HIDDEN_DOOR, cell);
        cell->setCell_type(CellSpace::TEMP_WALL);
        cell->setEvent(field.getEventFactory()->createEvent());
        return "Ok";
    }
};

#endif // SUBLEVELDOORRULE_H
