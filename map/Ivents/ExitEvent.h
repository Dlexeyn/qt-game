#ifndef EXITEVENT_H
#define EXITEVENT_H

#include "GlobalEvent.h"

class ExitEvent : public GlobalEvent
{
public:
    using GlobalEvent::GlobalEvent;
    void trigger();
};

#endif // EXITEVENT_H
