#ifndef CONDITIONSRULE_H
#define CONDITIONSRULE_H
#include "Field.h"

template <int victory, int hidDoor>
class ConditionsRule
{
public:
    ConditionsRule() {}
    std::string fill(map::Field &field)
    {
        if(victory <= 0 or hidDoor < 0 or
           victory > int(field.getBoxList().size()) or hidDoor > victory)
            return "Incorrect conditions";
        field.setCondition(hidDoor);
        field.setVictory(victory);
        return "Ok";
    }
};

#endif // CONDITIONSRULE_H
