#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include "LogData.h"
#include "FileLogDecorator.h"
#include "ConsoleLogDecorator.h"

class LogManager
{
public:
    LogManager();
    ~LogManager();
    Log::Message* writeSource(Log::Message *mes);
private:
    LogSource *source = nullptr;
    LogSource *fileSource = nullptr;
    LogSource *consoleSource = nullptr;
};

#endif // LOGMANAGER_H
