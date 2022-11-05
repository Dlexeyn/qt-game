#include "BoxView.h"

BoxView::BoxView(MapObject *object, ReadData *readData,
                 const std::vector<EventSubscriber *> &loggers, int index)
    : View(object, loggers)
{
    this->width = readData->getSizeCell()/1.4f;
    this->height = readData->getSizeCell()/1.4f;
    this->step = readData->getSizeCell();
    this->XY = new QPoint();
    this->XY->setX(readData->getBoxXY()[index]->x());
    this->XY->setY(readData->getBoxXY()[index]->y());
    this->XY = readData->getBoxXY()[index];
}

void BoxView::changeView()
{

}

void BoxView::setGameScene(QGraphicsScene *newGameScene, ReadData *data)
{
     newGameScene->addItem(this);
     this->setPos(data->getStartW() + data->getSizeCell() * XY->x(),
                  data->getStartH() + data->getSizeCell() * XY->y());
}

void BoxView::moving(int &stepX, int &stepY)
{
    setPos(mapToParent(step*stepX, step*stepY));
    XY->rx() += stepX;
    XY->ry() += stepY;

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

