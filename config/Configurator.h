#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <string>
#include "ConfigTypes.h"

namespace Config {
enum class Settings{
    LOGS,
    GAME
};

class Configurator
{
public:
    Configurator();
    virtual ~Configurator() = default;
    virtual void update(Settings part, std::string type, bool value) = 0;
};
}


#endif // CONFIGURATOR_H
