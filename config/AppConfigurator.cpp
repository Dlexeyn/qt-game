#include "AppConfigurator.h"

namespace Config {

AppConfigurator::AppConfigurator() {

    logMap["file"] = true;
    logMap["console"] = false;
    logMap["object"] = true;
    logMap["game"] = true;
    logMap["critical"] = true;
}

void AppConfigurator::update(std::string type, bool value)
{
    logMap[type] = value;
}

bool AppConfigurator::getFileLog() const
{
    return FileLog;
}

bool AppConfigurator::getConsoleLog() const
{
    return ConsoleLog;
}

bool AppConfigurator::getlog(std::string option)
{
    return logMap[option];
}

}
