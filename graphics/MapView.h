#ifndef MAPVIEW_H
#define MAPVIEW_H
#include "View.h"

class MapView: public View
{
public:
    using View::View;
    virtual void changeView(int type, int x, int y) = 0;
protected:
    QPoint *XYHidDoor = nullptr;
};


#endif // MAPVIEW_H
