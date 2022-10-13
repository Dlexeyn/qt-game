#include "Box.h"

void Box::sendCignal(int type)
{
    eventMediator->notify(this, "Box");
}

bool Box::getIsTargetPos() const
{
    return isTargetPos;
}

void Box::setIsTargetPos(bool newIsTargetPos)
{
    isTargetPos = newIsTargetPos;
}

void Box::changeStatus()
{

}
