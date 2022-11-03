#ifndef STATELOGGER_H
#define STATELOGGER_H

#include "Logger.h"

using namespace Log;

class StateLogger : public Logger
{
public:
    using Logger::Logger;
    void generateMessage(std::string type, std::string mes, LogArgs *logArgs = nullptr);
    void addExtraArgs(std::string &mes, LogArgs *args);
};

#endif // STATELOGGER_H
