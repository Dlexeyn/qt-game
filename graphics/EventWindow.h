#ifndef EVENTWINDOW_H
#define EVENTWINDOW_H

class EventWindow
{
public:
    virtual void callVictoryDialog() = 0;
    virtual void callRestartDialog() = 0;
    virtual void callExitDialog() = 0;
};

#endif // EVENTWINDOW_H
