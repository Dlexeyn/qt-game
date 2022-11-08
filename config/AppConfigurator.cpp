#include "AppConfigurator.h"

namespace Config {

AppConfigurator::AppConfigurator() {

    logMap["file"] = true;  // default settings
    logMap["console"] = true;
    logMap["object"] = true;
    logMap["game"] = true;
    logMap["critical"] = true;

    gameMap["lose_restart"] = true;
}

void AppConfigurator::update(Settings part, std::string type, bool value)
{
    switch (part) {
    case Settings::LOGS:
        logMap[type] = value;
        break;
    case Settings::GAME:
        gameMap[type] = value;
        break;
    }
}

bool AppConfigurator::getlog(std::string option)
{
    return logMap[option];
}

bool AppConfigurator::getGameOption(std::string option)
{
    return gameMap[option];
}

}
