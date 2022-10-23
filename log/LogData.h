#ifndef LOGDATA_H
#define LOGDATA_H

#include "LogSource.h"

class LogData : public LogSource
{
public:
    LogData(Log::Message *mes) : message(mes) {}
    Log::Message *sendMessage();
    void setLogSource(LogSource *newLogSource);
private:
    Log::Message *message;
};

#endif // LOGDATA_H
