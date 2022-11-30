#ifndef TRAPRULE_H
#define TRAPRULE_H
#include "Field.h"

template <int ...Args>
class TrapRule
{
public:
    TrapRule() {}
    std::string fill(map::Field &field)
    {
        addTrap<Args...>(field);
        if(err)
            return "going out of bounds in Trap XY";
        return "Ok";
    }
private:
    int err = 0;
    template <int x, int y, int ...nextArgs>
    void addTrap(map::Field &field)
    {
        if(x >= field.getMap_width() or y >= field.getMap_height()
                or x < 0 or y < 0 or err == -1)
        {
            err = -1;
            return;
        }
        Cell *cell = field.getMap_field()[y][x];
        field.getEventFactory()->setCurrentType(CellEventType::DESTROY_PLAYER, cell);
        cell->setCell_type(CellSpace::END_CELL);
        cell->setEvent(field.getEventFactory()->createEvent());
        if constexpr(sizeof...(nextArgs) > 0)
                 addTrap<nextArgs...>(field);
    }
};

#endif // TRAPRULE_H
