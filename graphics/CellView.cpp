#include "CellView.h"
#include "qpainter.h"
#include <map>

CellView::CellView(int width, int height, Cell *cell, QGraphicsScene *gameScene)
{
    this->width = width;
    this->height = height;
    this->type = cell->getCell_type();
    this->gameScene = gameScene;
    object = cell;
}

void CellView::changeView()
{
    type = (dynamic_cast<Cell*>(object))->getCell_type();
    this->hide();
    this->show();
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

void CellView::playerOnCell(Player *player)
{
    (dynamic_cast<Cell*>(object))->setPlayer(player);
    int changes = (dynamic_cast<Cell*>(object))->triggerForPlayer();
    if(changes)
        changeView();
}

void CellView::playerIsGone()
{
    (dynamic_cast<Cell*>(object))->setPlayer(nullptr);
}
