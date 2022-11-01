#ifndef GLOBALCOMPONENT_H
#define GLOBALCOMPONENT_H

#include "GlobalMediator.h"

class GlobalComponent
{
public:
    virtual void getMessage(GLMessage *mes) = 0;
    virtual ~GlobalComponent() = default;
    void setMediator(GlobalMediator *mediator);

protected:
    GlobalMediator *game;
};

inline void GlobalComponent::setMediator(GlobalMediator *mediator)
{
    game = mediator;
}

#endif // GLOBALCOMPONENT_H
