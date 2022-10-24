#ifndef EVENTFACTORY_H
#define EVENTFACTORY_H

#include "Event.h"

class EventFactory
{
public:
    virtual Event* createEvent() = 0;
    virtual ~EventFactory() = default;
};

#endif // EVENTFACTORY_H
