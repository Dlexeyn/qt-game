#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <QPainter>
#include <QGraphicsItem>
#include "game/Mediator.h"
#include "map/ReadData.h"
#include "objects/Player.h"
#include "View.h"

class PlayerView : public View, public QGraphicsItem
{

public:
    PlayerView(MapObject *object, ReadData *readData, QGraphicsScene *scene);

    void changeView();

    void moving(int &stepX, int &stepY);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

//    int getHealth();

//    int getPoints();

//    Player *getPlayer();

    QRectF boundingRect() const;


private:
    int step;
};

#endif // PLAYERVIEW_H
