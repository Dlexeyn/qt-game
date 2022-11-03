#ifndef GLOBALEVENTFACTORY_H
#define GLOBALEVENTFACTORY_H

#include "EventFactory.h"
#include "GlobalEvent.h"
#include "VictoryEvent.h"
#include "RestartEvent.h"
#include "LoseEvent.h"
#include "graphics/basewindow.h"

class GlobalEventFactory : public EventFactory
{
public:
    enum GlobalEventType{
        Victory,
        Restart,
        Lose
    };

    GlobalEventFactory(GlobalEventType type, BaseWindow *window) :
        currentType(type), window(window){}
    Event *createEvent();
    void setCurrentType(GlobalEventType newCurrentType);

private:
    GlobalEventType currentType;
    BaseWindow *window;
};

#endif // GLOBALEVENTFACTORY_H
