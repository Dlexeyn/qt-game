#ifndef EVENTFACTORY_H
#define EVENTFACTORY_H

#include "Event.h"

class EventFactory
{
public:
    EventFactory();
    virtual Event* createEvent() = 0;
};

#endif // EVENTFACTORY_H
