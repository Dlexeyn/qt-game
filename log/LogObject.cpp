#include "LogObject.h"

void LogObject::subscribe(const std::vector<EventSubscriber*> &arr)
{
    loggers = arr;
}

void LogObject::notifySubscribers(std::string str, std::string type, LogArgs *args)
{
    for(auto logger : loggers)
        logger->generateMessage(type, str, args);
}
