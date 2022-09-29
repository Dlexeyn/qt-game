#ifndef CELLVIEW_H
#define CELLVIEW_H

#include <QGraphicsItem>
#include <QPainter>
#include <QMap>
#include <QGraphicsScene>
#include "View.h"
#include "map/Cell.h"
#include "objects/Player.h"

class CellView : public QGraphicsItem, public View
{
public:
    CellView(int width, int height, Cell* cell, QGraphicsScene *gameScene);
    //~CellView(){}

    void changeView();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    bool isCellPassable();

    QRectF boundingRect() const;

    void playerOnCell(Player *player);

    void playerIsGone();

private:
    Cell::TypeOfCell type;
    QMap<Cell::TypeOfCell, Qt::GlobalColor> TypeColor = {{Cell::DIRT, Qt::gray},
                                                         {Cell::GRASS, Qt::green},
                                                         {Cell::LAVA, Qt::red},
                                                         {Cell::SAND, Qt::yellow},
                                                         {Cell::WATER, Qt::blue},
                                                         {Cell::TRAP, Qt::cyan},
                                                         {Cell::BROKEN_TRAP, Qt::darkCyan},
                                                         {Cell::WALL, Qt::darkGray}};

};

#endif // CELLVIEW_H
