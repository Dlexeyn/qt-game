#include "CellPainter.h"

CellPainter::CellPainter(int size, Cell *cell)
    : size(size), cell(cell), type(cell->getCell_type()){
    connect(cell, SIGNAL(typeChanged()), this, SLOT(changeView()));
}

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

void CellPainter::changeView()
{
    this->hide();
    setType(cell->getCell_type());
    this->show();
}
