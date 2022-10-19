#include "Controller.h"

void Controller::sendCignal()
{
    game->notify("controller");
}

void Controller::sendPlayerCommand(int command)
{
    stepY = stepX = 0;
    switch (command) {
    case UP:
        stepY = -1;
        break;
    case DOWN:
        stepY = 1;
        break;
    case LEFT:
        stepX = -1;
        break;
    case RIGHT:
        stepX = 1;
        break;
    default:
        return;
    }
    sendCignal();
}

int &Controller::getStepX()
{
    return stepX;
}

int &Controller::getStepY()
{
    return stepY;
}
