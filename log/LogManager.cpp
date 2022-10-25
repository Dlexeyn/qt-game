#include "LogManager.h"

LogManager::LogManager(Config::AppConfigurator *config) : config(config)
{
    fileSource = new FileLogDecorator();
    consoleSource = new ConsoleLogDecorator();
}

LogManager::~LogManager()
{
    delete fileSource;
    delete consoleSource;
    delete source;
}

Log::Message *LogManager::writeSource(Log::Message *mes)
{
    if(messageFilter(mes))
    {
        source = new LogData(mes);
        if(config->getlog("file") and config->getlog("console"))
        {
            consoleSource->setLogSource(source);
            fileSource->setLogSource(consoleSource);
            mes = fileSource->sendMessage();
        }
        else if(config->getlog("console"))
        {
            consoleSource->setLogSource(source);
            mes = consoleSource->sendMessage();
        }
        else if(config->getlog("file"))
        {
            fileSource->setLogSource(source);
            mes = fileSource->sendMessage();
        }
    }

    return mes;
}

bool LogManager::messageFilter(Log::Message *mes)
{
    Log::Type curType = mes->getType();
    bool value;
    switch (curType) {
    case Log::Type::ObjectState:
        value = config->getlog("object");
        break;
    case Log::Type::GlobalState:
        value = config->getlog("game");
        break;
    case Log::Type::CriticalState:
        value = config->getlog("critical");
        break;
    default:
        break;
    }
    return value;
}
