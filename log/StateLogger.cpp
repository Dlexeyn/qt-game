#include "StateLogger.h"

void StateLogger::generateMessage(std::string type, std::string mes)
{
    if(type == "warning")
    {
        Message *log = logManager->writeSource(new Message(Type::CriticalState, mes));
        delete log;
    }
}
