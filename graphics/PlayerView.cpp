#include "PlayerView.h"

PlayerView::PlayerView(MapObject *object, const std::vector<EventSubscriber *> &loggers, ReadData *readData)
    : View(object, loggers)
{
    this->width = readData->getSizeCell()-10;
    this->height = readData->getSizeCell()-10;
    this->XY = new QPoint();
    this->XY->setX(readData->getPlayerXY()->x());
    this->XY->setY(readData->getPlayerXY()->y());
    this->step = readData->getSizeCell();
}

void PlayerView::changeView()
{

}

void PlayerView::setGameScene(QGraphicsScene *newGameScene, ReadData *data)
{
    newGameScene->addItem(this);
    this->setPos(data->getStartW() + data->getSizeCell() * XY->x(),
                 data->getStartH() + data->getSizeCell() * XY->y());
}

void PlayerView::moving(int &stepX, int &stepY)
{
    setPos(mapToParent(step*stepX, step*stepY));
    XY->rx() += stepX;
    XY->ry() += stepY;
    notifySubscribers("Player changes position to ", "object", new LogArgs(ArgsLog::XY, XY->x(), XY->y()));
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

//int PlayerView::getHealth()
//{
//    return (dynamic_cast<Player*>(object))->getCurHealth();
//}

//int PlayerView::getPoints()
//{
//    return (dynamic_cast<Player*>(object))->getVictoryPoints();
//}

//Player *PlayerView::getPlayer()
//{
//    return (dynamic_cast<Player*>(object));
//}

QRectF PlayerView::boundingRect() const
{
    return QRectF(-width/2, height/2, width, height);
}

