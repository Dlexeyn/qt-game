#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <string>
#include "ConfigTypes.h"

namespace Config {
class Configurator
{
public:
    Configurator();
    virtual void update(ConfigTypes type, bool value) = 0;
};
}


#endif // CONFIGURATOR_H
