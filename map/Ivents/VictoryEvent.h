#ifndef VICTORYEVENT_H
#define VICTORYEVENT_H

#include "GlobalEvent.h"

class VictoryEvent : public GlobalEvent
{
public:
    VictoryEvent(EventWindow *window) : GlobalEvent(window) {}
    void trigger();
};

#endif // VICTORYEVENT_H
