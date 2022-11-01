#ifndef LOGDATA_H
#define LOGDATA_H

#include <iomanip>
#include <ctime>
#include <sstream>
#include "LogSource.h"

class LogData : public LogSource
{
public:
    LogData(){};
    Log::Message *writeMes(Log::Message *data);
};

#endif // LOGDATA_H
