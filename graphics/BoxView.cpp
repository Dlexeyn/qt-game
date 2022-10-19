#include "BoxView.h"

BoxView::BoxView(MapObject *object, ReadData *readData, int index, QGraphicsScene *scene) : View(object, scene)
{
    this->width = readData->getSizeCell()/1.4f;
    this->height = readData->getSizeCell()/1.4f;
    this->step = readData->getSizeCell();
    this->XY = new QPoint();
    this->XY->setX(readData->getBoxXY()[index]->x());
    this->XY->setY(readData->getBoxXY()[index]->y());
    this->XY = readData->getBoxXY()[index];
    scene->addItem(this);
    this->setPos(readData->getStartW() + readData->getSizeCell() * XY->x(),
                 readData->getStartH() + readData->getSizeCell() * XY->y());
}

void BoxView::changeView()
{

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
