#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <QPainter>
#include <QGraphicsItem>
#include "View.h"

class PlayerView : public View, public QGraphicsItem
{
public:

    PlayerView(int sizeCell, Object *object);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    QRectF boundingRect() const;
public slots:
    void setPosSlot(int x, int y);
};

#endif // PLAYERVIEW_H
