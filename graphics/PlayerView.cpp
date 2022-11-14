#include "PlayerView.h"


PlayerView::PlayerView(int sizeCell, Object *object)
    : View(sizeCell, object)
{
    width = step - 10;
    height = step - 10;
    connect(object, SIGNAL(changePosSignal(int,int)),
            this, SLOT(setPosSlot(int,int)));
}

void PlayerView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << QPoint(-width/2,-height/2) << QPoint(width/2,-height/2) << QPoint(width/2,height/2) << QPoint(-width/2, height/2);
    painter->setBrush(Qt::blue);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF PlayerView::boundingRect() const
{
    return QRectF(-width/2, height/2, width, height);
}

void PlayerView::setPosSlot(int x, int y)
{
    setPos(mapToParent(step*x, step*y));
}

