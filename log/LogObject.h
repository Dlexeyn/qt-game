#ifndef LOGOBJECT_H
#define LOGOBJECT_H

#include "EventSubscriber.h"
using namespace Log;

class LogObject
{
protected:
    EventSubscriber *logger = nullptr;
    Type type;

public:
    LogObject(){}
    void subscribe(EventSubscriber *newLogger, std::string typeStr);
    void notifySubscriber(std::string str, std::string type = "");

};


#endif // LOGOBJECT_H
