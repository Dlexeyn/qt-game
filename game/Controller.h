#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QPoint>
#include "graphics/FieldScene.h"
#include "GlobalComponent.h"
#include "GlobalMediator.h"

class Controller: public GlobalComponent
{
public:
    Controller(){}

    enum commands{
        UP = Qt::Key_W,
        DOWN = Qt::Key_S,
        LEFT = Qt::Key_A,
        RIGHT = Qt::Key_D
    };

    void sendCignal();

    void sendPlayerCommand(int command);
    int &getStepX();

    int &getStepY();

private:
    int stepX, stepY;
};

#endif // CONTROLLER_H
