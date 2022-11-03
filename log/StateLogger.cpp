#include "StateLogger.h"

void StateLogger::generateMessage(std::string type, std::string mes, LogArgs *logArgs)
{
    if(type == "warning")
    {
        if(logArgs)
            addExtraArgs(mes, logArgs);
        Message *log = logManager->writeSource(new Message(Type::CriticalState, mes));
        delete log;
    }
}

void StateLogger::addExtraArgs(std::string &mes, LogArgs *args)
{
    switch (args->getType())
    {
        case Log::ArgsLog::COUNT:
            mes = mes + std::to_string(*args->getArg1()) + " command(s)" ;
            break;
        default:
            break;
    }
}
