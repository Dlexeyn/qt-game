#include "LogManager.h"

LogManager::~LogManager()
{
    clearDecorators();
    delete source;
}

Log::Message *LogManager::writeSource(Log::Message *mes)
{
    if(!decorators.empty() and messageFilter(mes))
        decorators.back()->writeMes(mes);
    return mes;
}

void LogManager::initDecorators()
{
    clearDecorators();
    bool console = config->getlog("console");
    bool file = config->getlog("file");
    if(file and console)
    {
        decorators.push_back(new ConsoleLogDecorator(source));
        decorators.push_back(new FileLogDecorator(decorators.back()));
    }
    else if(console)
        decorators.push_back(new ConsoleLogDecorator(source));
    else if(file)
        decorators.push_back(new FileLogDecorator(source));
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

void LogManager::clearDecorators()
{
    for(auto decorator : decorators)
        delete decorator;
    decorators.clear();
}
