#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include "LogData.h"
#include "FileLogDecorator.h"
#include "ConsoleLogDecorator.h"
#include "config/AppConfigurator.h"

class LogManager
{
public:
    LogManager(Config::AppConfigurator *config);
    ~LogManager();
    Log::Message* writeSource(Log::Message *mes);
private:
    Config::AppConfigurator *config = nullptr;
    LogSource *source = nullptr;
    LogSource *fileSource = nullptr;
    LogSource *consoleSource = nullptr;

    bool messageFilter(Log::Message *mes);
};

#endif // LOGMANAGER_H
