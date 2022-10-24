#ifndef LOGGER_H
#define LOGGER_H

#include "LogManager.h"

namespace Log
{

class Logger : public EventSubscriber
{
public:
    Logger(LogManager *logManager) : logManager(logManager) {}
    ~Logger() {}

protected:
    LogManager *logManager = nullptr;
};
}




#endif // LOGGER_H
