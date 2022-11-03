#include "Point.h"

Point::Point(int x, int y)
{
    num = 0;
    setX(&x);
    setY(&y);
}

Point::Point()
{
    num = 0;
}

bool Point::isEmpty()
{
    if(!num)
        return true;
    else
        return false;
}

int *Point::getX() const
{
    return x;
}

void Point::setX(int *newX)
{
    if(x)
        delete x;
    x = newX;
    num++;
}

int *Point::getY() const
{
    return y;
}

void Point::setY(int *newY)
{
    if(y)
        delete y;
    y = newY;
    num++;
}

int Point::getNum() const
{
    return num;
}
