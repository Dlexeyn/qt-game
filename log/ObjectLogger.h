#ifndef OBJECTLOGGER_H
#define OBJECTLOGGER_H

#include "Logger.h"

using namespace Log;

class ObjectLogger : public Logger
{
public:
    using Logger::Logger;
    void generateMessage(std::string type, std::string mes);
};

#endif // OBJECTLOGGER_H
