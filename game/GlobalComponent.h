#ifndef GLOBALCOMPONENT_H
#define GLOBALCOMPONENT_H

#include "GlobalMediator.h"

class GlobalComponent
{
public:
    virtual void sendCignal() = 0;
    void setMediator(GlobalMediator *mediator);

protected:
    GlobalMediator *game;
};

inline void GlobalComponent::setMediator(GlobalMediator *mediator)
{
    game = mediator;
}

#endif // GLOBALCOMPONENT_H
