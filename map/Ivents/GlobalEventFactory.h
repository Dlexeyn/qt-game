#ifndef GLOBALEVENTFACTORY_H
#define GLOBALEVENTFACTORY_H

#include "EventFactory.h"
#include "graphics/EventWindow.h"

class GlobalEventFactory : public EventFactory
{
public:
    enum GlobalEventType{
        Victory,
        Restart,
        Lose
    };

    GlobalEventFactory(GlobalEventType type, EventWindow *window) :
        currentType(type), window(window){}
    Event *createEvent();
    void setCurrentType(GlobalEventType newCurrentType);

private:
    GlobalEventType currentType;
    EventWindow *window;
};

#endif // GLOBALEVENTFACTORY_H
