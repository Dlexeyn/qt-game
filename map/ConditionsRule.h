#ifndef CONDITIONSRULE_H
#define CONDITIONSRULE_H
#include "Field.h"
#include "map/GeneratorError.h"

template <int victory, int hidDoor>
class ConditionsRule
{
public:
    ConditionsRule() {}
    void fill(map::Field &field)
    {
        if(victory <= 0 or hidDoor < 0 or
           victory > int(field.getBoxList().size()) or hidDoor > victory)
            throw errors::GeneratorError(errors::Gen_Errors::CONDITION_ERR);

        field.setCondition(hidDoor);
        field.setVictory(victory);
    }
};

#endif // CONDITIONSRULE_H
