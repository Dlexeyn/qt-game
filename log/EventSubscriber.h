#ifndef EVENTSUBSCRIBER_H
#define EVENTSUBSCRIBER_H

#include <string>
#include "Message.h"

namespace Log
{
class EventSubscriber
{
public:
    virtual void generateMessage(Type type, std::string mes) = 0;
    virtual ~EventSubscriber() = default;
};
}

#endif // EVENTSUBSCRIBER_H
