#ifndef BOX_H
#define BOX_H

#include <iostream>
#include "log/LogObject.h"
#include "map/objects/Object.h"

class Box : public Object, public LogObject
{
public:
    Box(bool isTargetPos);
    Box(const Box& other);
    friend std::ostream& operator<<(std::ostream& out, const Box& obj){
        out << obj.pos.x() << "\n";
        out << obj.pos.y() << "\n";
        return out;
    }

private:
    bool isTargetPos;
};

#endif // BOX_H
