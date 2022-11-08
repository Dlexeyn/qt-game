#ifndef RESTARTEVENT_H
#define RESTARTEVENT_H

#include "GlobalEvent.h"

class RestartEvent : public GlobalEvent
{
public:
    using GlobalEvent::GlobalEvent;
    void trigger();
};

#endif // RESTARTEVENT_H
