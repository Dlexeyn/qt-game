#ifndef MAPVIEW_H
#define MAPVIEW_H
#include "View.h"

enum class ObjectType{
    PLAYER = 1,
    BOX = 2
};

class MapView: public View
{
public:
    using View::View;
    virtual void changeView(int x, int y) = 0;
    virtual bool isMoving(int x, int y) = 0;
    virtual void impactOnObject(ObjectType type, const int &x, const int &y) = 0;
protected:
    QPoint *XYHidDoor = nullptr;
};


#endif // MAPVIEW_H
