#ifndef VICTORYEVENT_H
#define VICTORYEVENT_H

#include "GlobalEvent.h"

class VictoryEvent : public GlobalEvent
{
public:
    using GlobalEvent::GlobalEvent;
    void trigger();
};

#endif // VICTORYEVENT_H
