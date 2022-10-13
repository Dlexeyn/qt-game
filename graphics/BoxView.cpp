#include "BoxView.h"

BoxView::BoxView(int width, int height, QPoint *XY, Box *box, int step)
{
    this->width = width;
    this->height = height;
    this->XY = XY;
    this->object = box;
    this->step = step;
}

void BoxView::changeView()
{

}

void BoxView::moving(int stepX, int stepY)
{
    setPos(mapToParent(step*stepX, step*stepY));
    XY->rx() += stepX;
    XY->ry() += stepY;
    dynamic_cast<Box*>(object)->sendCignal(1);
}

void BoxView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << QPoint(-width/2,-height/2) << QPoint(width/2,-height/2) << QPoint(width/2,height/2) << QPoint(-width/2, height/2);
    painter->setBrush(QColor(255, 192, 3));
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF BoxView::boundingRect() const
{
    return QRectF(-width/2, height/2, width, height);
}
