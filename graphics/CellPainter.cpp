#include "CellPainter.h"

void CellPainter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << QPoint(-size/2,-size/2) << QPoint(size/2,-size/2) << QPoint(size/2,size/2) << QPoint(-size/2, size/2);
    painter->setBrush(TypeColor.value(type));
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF CellPainter::boundingRect() const
{
    return QRectF(-size/2, size/2, size, size);
}

void CellPainter::setType(int newType)
{
    type = TypeOfCell(newType);
}
