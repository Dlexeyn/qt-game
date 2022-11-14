#ifndef CELLPAINTER_H
#define CELLPAINTER_H

#include "graphics/StaticView.h"
#include <QGraphicsItem>
#include <QMap>
#include <QPainter>
#include <map/Cell.h>

using namespace CellSpace;

class CellPainter: public QGraphicsItem, public StaticView
{
public:

    CellPainter(int size, Cell *cell);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QRectF boundingRect() const;
    void setType(int newType);

public slots:
    void changeView();

private:
    int size;   // in px
    Cell *cell = nullptr;
    TypeOfCell type;
    QMap<TypeOfCell, Qt::GlobalColor> TypeColor = {{DIRT, Qt::gray},
                                                   {GRASS, Qt::green},
                                                   {TRAP, Qt::cyan},
                                                   {BROKEN_TRAP, Qt::darkCyan},
                                                   {WALL, Qt::darkGray},
                                                   {TEMP_WALL, Qt::darkGray},
                                                   {TARGET_BOX, Qt::yellow},
                                                   {TARGET_WITH_BOX, Qt::darkGreen},
                                                   {END_CELL, Qt::red}};

};

#endif // CELLPAINTER_H
