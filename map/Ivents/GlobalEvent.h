#ifndef GLOBALEVENT_H
#define GLOBALEVENT_H

#include "Event.h"
#include "graphics/basewindow.h"

class GlobalEvent: public Event
{
public:
    GlobalEvent(BaseWindow *baseWindow) : baseWindow(baseWindow){}

protected:
    BaseWindow *baseWindow = nullptr;
};


#endif // GLOBALEVENT_H
