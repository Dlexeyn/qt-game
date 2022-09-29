#ifndef VIEW_H
#define VIEW_H

#include <QPoint>
#include <QGraphicsScene>
#include "map/MapObject.h"

class View
{
public:
    virtual void changeView() = 0;
    virtual ~View() = default;

    int getWidth() const;
    void setWidth(int newWidth);

    int getHeight() const;
    void setHeight(int newHeight);

    QPoint *getXY() const;
    void setXY(QPoint *newXY);

    MapObject *getObject() const;

protected:
    int width, height;
    QPoint *XY = nullptr;
    MapObject *object = nullptr;
    QGraphicsScene *gameScene = nullptr;
};

inline int View::getWidth() const
{
    return width;
}

inline void View::setWidth(int newWidth)
{
    width = newWidth;
}

inline int View::getHeight() const
{
    return height;
}

inline void View::setHeight(int newHeight)
{
    height = newHeight;
}

inline QPoint *View::getXY() const
{
    return XY;
}

inline void View::setXY(QPoint *newXY)
{
    XY = newXY;
}

inline MapObject *View::getObject() const
{
    return object;
}


#endif // VIEW_H
