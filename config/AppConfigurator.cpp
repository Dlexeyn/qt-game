#include "AppConfigurator.h"

namespace Config {

void AppConfigurator::update(ConfigTypes type, bool value)
{
    switch (type) {
    case ConfigTypes::LOG:
        FileLog = value;
        ConsoleLog = value;
        break;
    case ConfigTypes::FILE_LOG:
        FileLog = value;
        ConsoleLog = !value;
        break;
    case ConfigTypes::CONSOLE_LOG:
        ConsoleLog = value;
        FileLog = !value;
        break;
    default:
        break;
    }
}

bool AppConfigurator::getFileLog() const
{
    return FileLog;
}

bool AppConfigurator::getConsoleLog() const
{
    return ConsoleLog;
}

}
