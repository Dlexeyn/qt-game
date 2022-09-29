#include "Controller.h"

void Controller::sendPlayerCommand(int command)
{
    QPoint *curPos = fieldScene->getPlayerView()->getXY();
    int stepX = 0, stepY = 0;

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

    if(curPos->y() == 0 and command == UP)
        stepY = fieldScene->getCountCellsY()-1;
    else if(curPos->y() == fieldScene->getCountCellsY()-1 and command == DOWN)
        stepY = -(fieldScene->getCountCellsY()-1);
    else if(curPos->x() == 0 and command == LEFT)
        stepX = fieldScene->getCountCellsX()-1;
    else if(curPos->x() == fieldScene->getCountCellsX()-1 and command == RIGHT)
        stepX = -(fieldScene->getCountCellsX()-1);

    if(fieldScene->getCellView(curPos->x() + stepX, curPos->y() + stepY)->isCellPassable()) // fieldscene должно решать этот вопрос
        fieldScene->playerMove(stepX, stepY);

}
