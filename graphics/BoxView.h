#ifndef BOXVIEW_H
#define BOXVIEW_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPoint>
#include "View.h"

class BoxView : public View, public QGraphicsItem
{
public:
    BoxView(int sizeCell, Object *object);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    QRectF boundingRect() const;

public slots:
    void setPosSlot(int x, int y);
};

#endif // BOXVIEW_H
