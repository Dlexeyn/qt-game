#ifndef GAME_H
#define GAME_H

#include <QTimer>
#include "graphics/basewindow.h"
#include "Controller.h"


class Game
{
public:
    Game();

    void gameExecute();

private:
    BaseWindow *window = nullptr;
    Controller *controller = nullptr;
};

#endif // GAME_H
