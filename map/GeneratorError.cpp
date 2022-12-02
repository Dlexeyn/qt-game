#include "GeneratorError.h"



errors::GeneratorError::GeneratorError(Gen_Errors err, std::string str)
{
    switch (err) {
    case Gen_Errors::CONDITION_ERR:
        whatStr = "Incorrect conditions";
        break;
    case Gen_Errors::OUT_OF_BOUNDS_BOXES:
        whatStr = OUT_OF_BOUNDS + "box XY";
        break;
    case Gen_Errors::OUT_OF_BOUNDS_TARGETS:
        whatStr = OUT_OF_BOUNDS + "target XY";
        break;
    case Gen_Errors::OUT_OF_BOUNDS_TRAPS:
        whatStr = OUT_OF_BOUNDS + "trap XY";
        break;
    case Gen_Errors::OUT_OF_BOUNDS_DOORS:
        whatStr = OUT_OF_BOUNDS + "hidDoor XY";
        break;
    case Gen_Errors::OUT_OF_BOUNDS_PLAYER:
        whatStr = OUT_OF_BOUNDS + "player XY";
        break;
    case Gen_Errors::FILE_ERR:
        whatStr = "the file " + str + " deleted or corrupted";
        break;
    case Gen_Errors::NUM_ERR:
        whatStr = "incorrect num of boxes";
        break;
    }
}

const char *errors::GeneratorError::what() const noexcept
{
    return whatStr.c_str();
}
