#ifndef OBJECT_H
#define OBJECT_H

#include <QPoint>
#include <QObject>

class Object: public QObject
{
Q_OBJECT
public:
    int getPos(bool isX) const;
    void setPos(int x, int y);
signals:
    void changePosSignal(int x, int y);

protected:
    QPoint pos;
    bool isDestroyed = false;
};

inline int Object::getPos(bool isX) const
{
    if(isX)
        return pos.x();
    return pos.y();
}

inline void Object::setPos(int x, int y)
{
    pos.setX(x);
    pos.setY(y);
}

#endif // OBJECT_H
