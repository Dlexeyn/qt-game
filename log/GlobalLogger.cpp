#include "GlobalLogger.h"

void GlobalLogger::generateMessage(std::string type, std::string mes, LogArgs *logArgs)
{
    if(type == "global" or type == "game")
    {
        if(logArgs)
            addExtraArgs(mes, logArgs);
        Message *log = logManager->writeSource(new Message(Type::GlobalState, mes));
        delete log;
    }
}

void GlobalLogger::addExtraArgs(std::string &mes, LogArgs *args)
{
    switch (args->getType()) {
    case Log::ArgsLog::LEVEL:
        mes = mes + std::to_string(*args->getArg1()) + " has started";
        break;
    default:
        break;
    }
}
