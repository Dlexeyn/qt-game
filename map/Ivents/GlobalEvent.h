#ifndef GLOBALEVENT_H
#define GLOBALEVENT_H

#include "Event.h"
#include "graphics/EventWindow.h"

class GlobalEvent: public Event
{
public:
    GlobalEvent(EventWindow *baseWindow) : baseWindow(baseWindow){}

protected:
    EventWindow *baseWindow = nullptr;
};


#endif // GLOBALEVENT_H
