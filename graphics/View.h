#ifndef VIEW_H
#define VIEW_H

#include <QPoint>
#include <QObject>
#include "map/objects/Object.h"

class View: public QObject
{
    Q_OBJECT
public:
    View(int sizeCell, Object *object)
        : step(sizeCell), object(object){}

public slots:
    virtual void setPosSlot(int x, int y) = 0;
protected:
    int width, height, step;
    QPoint *XY = nullptr;
    Object *object = nullptr;
};



#endif // VIEW_H
