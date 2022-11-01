#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QPoint>
#include "graphics/FieldScene.h"
#include "GlobalComponent.h"

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

    void getMessage(GLMessage *mes);

    int &getStepX();

    int &getStepY();

private:
    int stepX, stepY;
    void sendPlayerCommand(int command);
};

#endif // CONTROLLER_H
