#include "ObjectLogger.h"

void ObjectLogger::generateMessage(std::string type, std::string mes)
{
    if(type == "object" or type == "event")
    {
        Message *log = logManager->writeSource(new Message(Type::ObjectState, mes));
        delete log;
    }
}
