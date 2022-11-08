#ifndef APPCONFIGURATOR_H
#define APPCONFIGURATOR_H

#include "Configurator.h"
#include <map>

namespace Config {
class AppConfigurator : public Configurator
{
public:
    AppConfigurator();
    void update(Settings part, std::string type, bool value);
    bool getlog(std::string option);
    bool getGameOption(std::string option);

private:
    std::map <std::string, bool> logMap;
    std::map <std::string, bool> gameMap;
};
}


#endif // APPCONFIGURATOR_H
