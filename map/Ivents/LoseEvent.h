#ifndef LOSEEVENT_H
#define LOSEEVENT_H

#include "GlobalEvent.h"

class LoseEvent : public GlobalEvent
{
public:
    using GlobalEvent::GlobalEvent;
    void trigger();
};

#endif // LOSEEVENT_H
