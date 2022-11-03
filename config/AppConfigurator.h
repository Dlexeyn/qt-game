#ifndef APPCONFIGURATOR_H
#define APPCONFIGURATOR_H

#include "Configurator.h"
#include <map>

namespace Config {
class AppConfigurator : public Configurator
{
public:
    AppConfigurator();
    void update(std::string type, bool value);
    bool getlog(std::string option);

private:
    std::map <std::string, bool> logMap;
};
}


#endif // APPCONFIGURATOR_H
