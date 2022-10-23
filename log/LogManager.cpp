#include "LogManager.h"

LogManager::LogManager()
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
    source = new LogData(mes);
    consoleSource->setLogSource(source);
    fileSource->setLogSource(consoleSource);
    return fileSource->sendMessage();
}
