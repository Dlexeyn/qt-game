#ifndef SAVEHELPER_H
#define SAVEHELPER_H

#include <string>
#include <map>
#include "map/Cell.h"
namespace save {

enum class PARAMS{
    HEIGHT,
    WIDTH,
    STEP,
    CONDITION,
    VICTORY,
    MAP,
    HidDoorX,
    HidDoorY,
    Count_Boxes
};

class SaveHelper
{
    std::map<CellSpace::TypeOfCell, char> map_char =
    {
        {CellSpace::GRASS, 'g'},
        {CellSpace::WALL, 'w'},
        {CellSpace::TEMP_WALL, 'W'},
        {CellSpace::TARGET_BOX, 't'},
        {CellSpace::TARGET_WITH_BOX, 'T'},
        {CellSpace::END_CELL, 'e'}
    };
    std::map<char, CellSpace::TypeOfCell> map_type;
public:
    SaveHelper();
    std::map<PARAMS, std::string> parms_map = {
        {PARAMS::HEIGHT, "HEIGHT"},
        {PARAMS::WIDTH, "WIDTH"},
        {PARAMS::STEP, "STEP"},
        {PARAMS::CONDITION, "HIDDOR_CONDTITION"},
        {PARAMS::VICTORY, "VICTORY_CONDTITION"},
        {PARAMS::MAP, "MAP"},
        {PARAMS::HidDoorX, "HIDDOR_X"},
        {PARAMS::HidDoorY, "HIDDOR_Y"},
        {PARAMS::Count_Boxes, "COUNT_BOXES"}
    };
    char getSym(CellSpace::TypeOfCell type) { return map_char[type]; }
    CellSpace::TypeOfCell getType(char c) { return map_type[c]; }
};

}


#endif // SAVEHELPER_H
