#ifndef CELLVIEW_H
#define CELLVIEW_H

#include <QGraphicsItem>
#include <QPainter>
#include <QMap>
#include <QGraphicsScene>
#include "View.h"
#include "map/Cell.h"
#include "objects/Player.h"

using namespace CellSpace;

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
    TypeOfCell type;
    QMap<TypeOfCell, Qt::GlobalColor> TypeColor = {{DIRT, Qt::gray},
                                                         {GRASS, Qt::green},
                                                         {TRAP, Qt::cyan},
                                                         {BROKEN_TRAP, Qt::darkCyan},
                                                         {WALL, Qt::darkGray},
                                                         {TARGET_BOX, Qt::yellow},
                                                         {TARGET_WITH_BOX, Qt::darkGreen},
                                                   {END_CELL, Qt::red}};

};

#endif // CELLVIEW_H
