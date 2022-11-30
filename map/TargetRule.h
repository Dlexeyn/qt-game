#ifndef TARGETRULE_H
#define TARGETRULE_H
#include "Field.h"

template <int ...Args>
class TargetsRule
{
public:
    TargetsRule() {}
    std::string fill(map::Field &field)
    {
        addTarget<Args...>(field);
        if(err)
            return "going out of bounds in Targets XY";
        return "Ok";

    }
private:
    int err = 0;
    template <int x, int y, int ...nextArgs>
    void addTarget(map::Field &field)
    {
        if(x >= field.getMap_width() or y >= field.getMap_height()
                        or x < 0 or y < 0 or err == -1)
        {
            err = -1;
            return;
        }
        Cell *cell = field.getMap_field()[y][x];
        field.getEventFactory()->setCurrentType(CellEventType::COLOR_BOX, cell);
        cell->setCell_type(CellSpace::TARGET_BOX);
        cell->setEvent(field.getEventFactory()->createEvent());
        if constexpr(sizeof...(nextArgs) > 0)
                 addTarget<nextArgs...>(field);
    }
};

#endif // TARGETRULE_H
