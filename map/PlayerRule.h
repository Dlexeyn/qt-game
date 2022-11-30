#ifndef PLAYERRULE_H
#define PLAYERRULE_H

#include <iostream>
#include "Field.h"

template <int x, int y>
class PlayerRule
{
public:
    PlayerRule() {}
    std::string fill(map::Field &field)
    {
        field.setPlayer(new Player);
        field.getEventFactory()->setPlayer(field.getPlayer());

        if(x > field.getMap_width() or y > field.getMap_height()
                or x < 0 or y < 0)
            return "going out of bounds in Player XY";

        field.getPlayer()->setPos(x, y);
        return "Ok";
    }
};

#endif // PLAYERRULE_H
