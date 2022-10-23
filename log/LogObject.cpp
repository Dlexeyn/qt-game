#include "LogObject.h"



void LogObject::subscribe(EventSubscriber *newLogger, std::string typeStr)
{
    logger = newLogger;
    if(typeStr == "obj")
        type = Log::Type::ObjectState;
    else if(typeStr == "global")
        type = Log::Type::GlobalState;
    else
        type = Log::Type::CriticalState;
}

void LogObject::notifySubscriber(std::string str)
{
    logger->generateMessage(type, str);
}
