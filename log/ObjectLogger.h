#ifndef OBJECTLOGGER_H
#define OBJECTLOGGER_H

#include "Logger.h"

using namespace Log;

class ObjectLogger : public Logger
{
public:
    using Logger::Logger;
    void generateMessage(std::string type, std::string mes, LogArgs *logArgs = nullptr);
    void addExtraArgs(std::string &mes, LogArgs *args);
};

#endif // OBJECTLOGGER_H
