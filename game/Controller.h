#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QPoint>
#include "graphics/FieldScene.h"


class Controller
{
public:
    Controller(FieldScene *fieldScene): fieldScene(fieldScene){}

    enum commands{
        UP = Qt::Key_W,
        DOWN = Qt::Key_S,
        LEFT = Qt::Key_A,
        RIGHT = Qt::Key_D
    };

    void sendPlayerCommand(int command);
private:
    FieldScene *fieldScene = nullptr;
};

#endif // CONTROLLER_H
