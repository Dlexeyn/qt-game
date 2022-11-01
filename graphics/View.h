#ifndef VIEW_H
#define VIEW_H

#include <QPoint>
#include <QGraphicsScene>
#include <log/LogObject.h>
#include "map/ReadData.h"
#include "map/MapObject.h"

class View: public LogObject
{
public:
    View(MapObject *object, const std::vector<EventSubscriber *> &loggers) : object(object)
    {
        subscribe(loggers);
    }
    virtual ~View() = default;

    virtual void moving(int &stepX, int &stepY) = 0;
    virtual void setGameScene(QGraphicsScene *newGameScene, ReadData *data) = 0;

    int getWidth() const;
    void setWidth(int newWidth);

    int getHeight() const;
    void setHeight(int newHeight);

    QPoint *getXY() const;
    void setXY(QPoint *newXY);

    MapObject *getObject() const;

    void setObject(MapObject *newObject);

    QGraphicsScene *getGameScene() const;


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

inline void View::setObject(MapObject *newObject)
{
    object = newObject;
}

inline QGraphicsScene *View::getGameScene() const
{
    return gameScene;
}


#endif // VIEW_H
