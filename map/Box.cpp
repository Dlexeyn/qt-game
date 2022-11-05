#include "Box.h"

Box::Box(bool isTargetPos, const std::vector<EventSubscriber *> &loggers) : isTargetPos(isTargetPos)
{
    subscribe(loggers);
    isActive = true;
}

void Box::sendCignal()
{
    eventMediator->notify("Box");
}

int Box::getAttribute(ObjectAttribute at) const
{

}

void Box::setAttribute(ObjectAttribute at, int arg)
{

}

bool Box::getIsTargetPos() const
{
    return isTargetPos;
}

void Box::setIsTargetPos(bool newIsTargetPos)
{
    isTargetPos = newIsTargetPos;
}

bool Box::checkState()
{
    return isTargetPos;
}

int Box::changeStatus()
{
    return 1;
}

void Box::callAnObject()
{
}
