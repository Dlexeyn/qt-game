#ifndef APPCONFIGURATOR_H
#define APPCONFIGURATOR_H

#include "Configurator.h"

namespace Config {
class AppConfigurator : public Configurator
{
public:
    AppConfigurator() {}
    void update(ConfigTypes type, bool value);
    bool getFileLog() const;

    bool getConsoleLog() const;

private:
    bool FileLog = false;
    bool ConsoleLog = false;
};
}


#endif // APPCONFIGURATOR_H
