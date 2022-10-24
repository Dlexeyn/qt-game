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
    source = new LogData(mes); 

    if(config->getConsoleLog() and config->getFileLog())
    {
        consoleSource->setLogSource(source);
        fileSource->setLogSource(consoleSource);
        mes = fileSource->sendMessage();
    }
    else if(config->getConsoleLog())
    {
        consoleSource->setLogSource(source);
        mes = consoleSource->sendMessage();
    }
    else if(config->getFileLog())
    {
        fileSource->setLogSource(source);
        mes = fileSource->sendMessage();
    }

    return mes;
}
