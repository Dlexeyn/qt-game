#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <QPainter>
#include <QGraphicsItem>
#include "objects/Player.h"
#include "View.h"

class PlayerView : public View, public QGraphicsItem
{

public:
    PlayerView(int width, int height, int x, int y, Player *player, int step);

    void changeView();

    void moving(int stepX, int stepY);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    int getHealth();

    Player *getPlayer();

    QRectF boundingRect() const;


private:
    int step;
};

#endif // PLAYERVIEW_H
