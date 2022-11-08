#ifndef EVENTWINDOW_H
#define EVENTWINDOW_H

#include "BaseWindowStatus.h"
#include "game/GlobalComponent.h"

class EventWindow: public GlobalComponent
{
public:
    virtual void callVictoryEventDialog() = 0;
    virtual bool callRestartEventDialog(bool withQuestion) = 0;
    virtual void callLoseEventDialog() = 0;
    virtual void setStatus(WindowStatus newStatus) = 0;
};

#endif // EVENTWINDOW_H
