#ifndef CELLPAINTER_H
#define CELLPAINTER_H

#include <QGraphicsItem>
#include <QMap>
#include <QPainter>
#include <map/Cell.h>

using namespace CellSpace;

class CellPainter: public QGraphicsItem
{
public:

    CellPainter(int size, TypeOfCell type) : size(size), type(type){}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QRectF boundingRect() const;
    void setType(int newType);

private:
    int size;   // in px
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
