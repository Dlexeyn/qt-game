#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point(int x, int y);
    Point();

    bool isEmpty();

    int *getX() const;
    void setX(int *newX);

    int *getY() const;
    void setY(int *newY);

    int getNum() const;

private:
    int *x = nullptr, *y = nullptr;
    int num;
};

#endif // POINT_H
