#include "PlayerView.h"

PlayerView::PlayerView(int width, int height, int x, int y, Player *player, int step)
{
    this->width = width;
    this->height = height;
    this->setXY(new QPoint(x, y));
    this->object = player;
    this->step = step;
}

void PlayerView::changeView()
{

}

void PlayerView::moving(int stepX, int stepY)
{
    setPos(mapToParent(step*stepX, step*stepY));
    XY->rx() += stepX;
    XY->ry() += stepY;
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

int PlayerView::getHealth()
{
    return (dynamic_cast<Player*>(object))->getCurHealth();
}

Player *PlayerView::getPlayer()
{
    return (dynamic_cast<Player*>(object));
}

QRectF PlayerView::boundingRect() const
{
    return QRectF(-width/2, height/2, width, height);
}

