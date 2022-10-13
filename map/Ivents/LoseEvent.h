#ifndef LOSEEVENT_H
#define LOSEEVENT_H

#include "GlobalEvent.h"

class LoseEvent : public GlobalEvent
{
public:
    LoseEvent(EventWindow *window) : GlobalEvent(window) {}
    void trigger();
};

#endif // LOSEEVENT_H
