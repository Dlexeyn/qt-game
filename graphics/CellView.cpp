#include "CellView.h"
#include "qpainter.h"
#include <map>

CellView::CellView(int width, int height, Cell *cell)
{
    this->width = width;
    this->height = height;
    this->type = cell->getCell_type();
    object = cell;

}

void CellView::changeView()
{

}

void CellView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << QPoint(-width/2,-height/2) << QPoint(width/2,-height/2) << QPoint(width/2,height/2) << QPoint(-width/2, height/2);
    painter->setBrush(TypeColor.value(this->type));
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

bool CellView::isCellPassable()
{
    return dynamic_cast<Cell*>(object)->getIsPassable();
}

QRectF CellView::boundingRect() const
{
    return QRectF(-width/2, height/2, width, height);
}
