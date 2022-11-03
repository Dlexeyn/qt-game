#include "ObjectLogger.h"

void ObjectLogger::generateMessage(std::string type, std::string mes, LogArgs *logArgs)
{
    if(type == "object" or type == "event")
    {
        if(logArgs)
            addExtraArgs(mes, logArgs);
        Message *log = logManager->writeSource(new Message(Type::ObjectState, mes));
        delete log;
    }
}

void ObjectLogger::addExtraArgs(std::string &mes, LogArgs *args)
{
    switch (args->getType()) {
    case ArgsLog::XY:
        mes = mes + std::to_string(*args->getArg1()) + ", " + std::to_string(*args->getArg2());
        break;
    case ArgsLog::SIZE_WH:
        mes = mes + std::to_string(*args->getArg1()) + " x " + std::to_string(*args->getArg2());
        break;
    case ArgsLog::SIZE:
        mes = mes + std::to_string(*args->getArg1());
        break;
    default:
        break;
    }
}
