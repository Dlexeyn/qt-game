#ifndef BOX_H
#define BOX_H

#include "map/MapComponent.h"

class Box : public MapComponent
{
public:
    Box(bool isTargetPos, const std::vector<EventSubscriber *> &loggers);
    void sendCignal();

    int getAttribute(ObjectAttribute at) const;
    void setAttribute(ObjectAttribute at, int arg);

    bool getIsTargetPos() const;
    void setIsTargetPos(bool newIsTargetPos);
    bool checkState();

    int changeStatus();
    void callAnObject();

private:
    bool isTargetPos;
    bool isActive;
};

#endif // BOX_H
