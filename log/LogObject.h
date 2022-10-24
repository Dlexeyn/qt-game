#ifndef LOGOBJECT_H
#define LOGOBJECT_H

#include "EventSubscriber.h"
#include "vector"
using namespace Log;

class LogObject
{
protected:
    std::vector<EventSubscriber*> loggers;

public:
    LogObject(){}
    void subscribe(const std::vector<EventSubscriber *> &arr);
    void notifySubscribers(std::string str, std::string type = "");

};


#endif // LOGOBJECT_H
