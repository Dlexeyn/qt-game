#include "Box.h"

Box::Box(bool isTargetPos) : isTargetPos(isTargetPos)
{
    isDestroyed = false;
}

Box::Box(const Box &other)
{
    pos = other.pos;
    isDestroyed = other.isDestroyed;
}


