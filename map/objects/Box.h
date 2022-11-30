#ifndef BOX_H
#define BOX_H

#include "log/LogObject.h"
#include "map/objects/Object.h"

class Box : public Object, public LogObject
{
public:
    Box(bool isTargetPos);
    Box(const Box& other);

private:
    bool isTargetPos;
};

#endif // BOX_H
