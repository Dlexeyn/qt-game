#ifndef BOX_H
#define BOX_H

#include "MapObject.h"
#include "map/MapComponent.h"
#include "game/Mediator.h"

class Box : public MapComponent
{
public:
    void sendCignal(int type);
    Box(bool isTargetPos) : isTargetPos(isTargetPos) {}
    bool getIsTargetPos() const;
    void setIsTargetPos(bool newIsTargetPos);

    void changeStatus();

private:
    bool isTargetPos;
};

#endif // BOX_H
