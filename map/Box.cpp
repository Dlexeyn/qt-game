#include "Box.h"

Box::Box(bool isTargetPos, const std::vector<EventSubscriber *> &loggers) : isTargetPos(isTargetPos)
{
    subscribe(loggers);
}

void Box::sendCignal(int type)
{
    eventMediator->notify(this, "Box");
}

int Box::getFirstAttribute() const
{
    return isTargetPos;
}

int Box::getSecondAttribute() const
{
    return 1;
}

void Box::setFirstAttribute(int newAttribute)
{
    isTargetPos = bool(newAttribute);
}

void Box::setSecondAttribute(int newAttribute)
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

int Box::callAnObject()
{
    return getIsTargetPos();
}
