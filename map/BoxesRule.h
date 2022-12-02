#ifndef BOXESRULE_H
#define BOXESRULE_H
#include <qpoint.h>
#include <iostream>
#include "Field.h"
#include "map/GeneratorError.h"

template <int num, int ...Args>
class BoxesRule
{
public:
    BoxesRule() {}
    void fill(map::Field &field)
    {
        if(sizeof...(Args) == num * 2)
        {
            field.setBoxList(std::vector<Box*>(num, nullptr));
            addBox<Args...>(field);
        }
        else
            throw errors::GeneratorError(errors::Gen_Errors::NUM_ERR);
    }
private:
    int index = 0;
    template <int x, int y, int ...args>
    void addBox(map::Field &field)
    {
        if(x >= field.getMap_width() or y >= field.getMap_height()
                or x < 0 or y < 0)
            throw errors::GeneratorError(errors::Gen_Errors::OUT_OF_BOUNDS_BOXES);

        Box *newBox = new Box(false);
        newBox->setPos(x, y);
        field.addBox(index++, newBox);
        if constexpr(sizeof...(args) > 0)
                addBox<args ...>(field);
    }
};

#endif // BOXESRULE_H
