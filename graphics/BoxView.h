#ifndef BOXVIEW_H
#define BOXVIEW_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPoint>
#include "View.h"
#include "map/Box.h"
#include "map/GameMediator.h"
#include "map/ReadData.h"

class BoxView : public QGraphicsItem, public View
{
public:
    BoxView(MapObject *object, ReadData *readData, int index, QGraphicsScene *scene);

    void changeView();

    void moving(int &stepX, int &stepY);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    QRectF boundingRect() const;

private:
    int step;
};

#endif // BOXVIEW_H
