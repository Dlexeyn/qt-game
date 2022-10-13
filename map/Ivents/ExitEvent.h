#ifndef EXITEVENT_H
#define EXITEVENT_H

#include "GlobalEvent.h"

class ExitEvent : public GlobalEvent
{
public:
    ExitEvent(EventWindow *window) : GlobalEvent(window) {}
    void trigger();
};

#endif // EXITEVENT_H
