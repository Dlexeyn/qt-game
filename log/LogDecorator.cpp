#include "LogDecorator.h"

Log::Message *LogDecorator::sendMessage()
{
    return logSource->sendMessage();
}

void LogDecorator::setLogSource(LogSource *newLogSource)
{
    logSource = newLogSource;
}
