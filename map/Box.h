#ifndef BOX_H
#define BOX_H

#include "MapObject.h"
#include "map/MapComponent.h"
#include "game/Mediator.h"

class Box : public MapComponent
{
public:
    void sendCignal(int type);

    int getFirstAttribute() const;  // return bool isTargetPos
    int getSecondAttribute() const;
    void setFirstAttribute(int newAttribute);
    void setSecondAttribute(int newAttribute);
    Box(bool isTargetPos) : isTargetPos(isTargetPos) {}
    bool getIsTargetPos() const;
    void setIsTargetPos(bool newIsTargetPos);
    bool checkState();

    int changeStatus();
    int callAnObject();

private:
    bool isTargetPos;
};

#endif // BOX_H
