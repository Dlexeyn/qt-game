#ifndef BOXVIEW_H
#define BOXVIEW_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPoint>
#include "View.h"
#include "map/Box.h"
#include "map/GameMediator.h"

class BoxView : public QGraphicsItem, public View
{
public:
    BoxView(int width, int height, QPoint *XY, Box *box, int step);

    void changeView();

    void moving(int stepX, int stepY);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    QRectF boundingRect() const;

private:
    int step;
};

#endif // BOXVIEW_H
