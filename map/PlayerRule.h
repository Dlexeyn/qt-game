#ifndef PLAYERRULE_H
#define PLAYERRULE_H

#include <iostream>
#include "Field.h"
#include "map/GeneratorError.h"

template <int x, int y>
class PlayerRule
{
public:
    PlayerRule() {}
    void fill(map::Field &field)
    {
        field.setPlayer(new Player);
        field.getEventFactory()->setPlayer(field.getPlayer());

        if(x > field.getMap_width() or y > field.getMap_height()
                or x < 0 or y < 0)
            throw errors::GeneratorError(errors::Gen_Errors::OUT_OF_BOUNDS_PLAYER);
        field.getPlayer()->setPos(x, y);
    }
};

#endif // PLAYERRULE_H
