#ifndef GENERATORERROR_H
#define GENERATORERROR_H

#include <stdexcept>

namespace errors {

enum class Gen_Errors
{
    CONDITION_ERR,
    OUT_OF_BOUNDS_BOXES,
    OUT_OF_BOUNDS_TARGETS,
    OUT_OF_BOUNDS_TRAPS,
    OUT_OF_BOUNDS_DOORS,
    OUT_OF_BOUNDS_PLAYER,
    FILE_ERR,
    NUM_ERR
};

class GeneratorError: std::exception
{
    const std::string OUT_OF_BOUNDS = "going out of bounds in ";
    std::string whatStr;
public:
    explicit GeneratorError(Gen_Errors err, std::string str = "");
    const char *what() const noexcept override;
};
}


#endif // GENERATORERROR_H
