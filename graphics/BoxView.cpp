#include "BoxView.h"


BoxView::BoxView(int sizeCell, Object *object)
    : View(sizeCell, object)
{
    width = step / 1.4f;
    height = step / 1.4f;
    connect(object, SIGNAL(changePosSignal(int,int)),
            this, SLOT(setPosSlot(int,int)));
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

void BoxView::setPosSlot(int x, int y)
{
    this->QGraphicsItem::setPos(mapToParent(step*x, step*y));
}

