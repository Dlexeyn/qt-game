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
    bool getFileLog() const;

    bool getConsoleLog() const;

    bool getlog(std::string option);

private:
    std::map <std::string, bool> logMap;
    bool FileLog = true;
    bool ConsoleLog = true;
    bool ObjectState = true;
    bool GameState = true;
    bool CriticalState = true;
};
}


#endif // APPCONFIGURATOR_H
