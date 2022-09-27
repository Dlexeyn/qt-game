#ifndef CELLVIEW_H
#define CELLVIEW_H

#include <QGraphicsItem>
#include <QPainter>
#include <QMap>
#include "View.h"
#include "map/Cell.h"

class CellView : public QGraphicsItem, public View
{
public:
    CellView(int width, int height, Cell* cell);
    //~CellView(){}

    void changeView();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    bool isCellPassable();

    QRectF boundingRect() const;

private:
    Cell::TypeOfCell type;
    QMap<Cell::TypeOfCell, Qt::GlobalColor> TypeColor = {{Cell::DIRT, Qt::gray},
                                                         {Cell::GRASS, Qt::green},
                                                         {Cell::LAVA, Qt::red},
                                                         {Cell::SAND, Qt::yellow},
                                                         {Cell::WATER, Qt::blue}};

};

#endif // CELLVIEW_H
