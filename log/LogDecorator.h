#ifndef LOGDECORATOR_H
#define LOGDECORATOR_H

#include "LogSource.h"

class LogDecorator : public LogSource
{
public:
    LogDecorator(LogSource *logSource) : logSource(logSource) {}
    LogDecorator() {}
    Log::Message *sendMessage();
    void setLogSource(LogSource *newLogSource);

protected:
    LogSource *logSource = nullptr;
};

#endif // LOGDECORATOR_H
