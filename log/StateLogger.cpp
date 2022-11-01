#include "StateLogger.h"

void StateLogger::generateMessage(std::string type, std::string mes, LogArgs *logArgs)
{
    if(type == "warning")
    {
        Message *log = logManager->writeSource(new Message(Type::CriticalState, mes));
        delete log;
    }
}
