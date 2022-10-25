#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <string>
#include "ConfigTypes.h"

namespace Config {
class Configurator
{
public:
    Configurator();
    virtual void update(std::string type, bool value) = 0;
};
}


#endif // CONFIGURATOR_H
