#ifndef RESTARTEVENT_H
#define RESTARTEVENT_H

#include "GlobalEvent.h"

class RestartEvent : public GlobalEvent
{
public:
    //RestartEvent();
    void trigger();
};

#endif // RESTARTEVENT_H
