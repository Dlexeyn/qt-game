#include "Controller.h"

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
    GLMessage newMes(Sender::CONTROLLER, ArgsTypes::X, stepX);
    newMes.addArg(ArgsTypes::Y, stepY);
    game->notify(this, &newMes);
}

void Controller::getMessage(GLMessage* mes)
{
    sendPlayerCommand(mes->getArg(ArgsTypes::KEY));
}


int &Controller::getStepX()
{
    return stepX;
}

int &Controller::getStepY()
{
    return stepY;
}
