#ifndef EVENTSUBSCRIBER_H
#define EVENTSUBSCRIBER_H

#include <string>
#include <vector>
#include "LogArgs.h"

namespace Log
{
class EventSubscriber
{
public:
    virtual void generateMessage(std::string type, std::string mes, LogArgs *logArgs = nullptr) = 0;
    virtual ~EventSubscriber() = default;
};
}

#endif // EVENTSUBSCRIBER_H
