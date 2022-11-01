#ifndef GLOBALLOGGER_H
#define GLOBALLOGGER_H

#include "Logger.h"

using namespace Log;

class GlobalLogger : public Logger
{
public:
    using Logger::Logger;
    void generateMessage(std::string type, std::string mes, LogArgs *logArgs = nullptr);
    void addExtraArgs(std::string &mes, LogArgs *args);
};

#endif // GLOBALLOGGER_H
