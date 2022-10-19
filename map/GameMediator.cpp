#include "GameMediator.h"
#include <QDebug>

GameMediator::GameMediator(MapComponent *field, MapComponent *player, std::vector<MapComponent *> &listBox, ReadData *readData)
: field(field), player(player), listBox(listBox), readData(readData)
{

}

void GameMediator::notify(MapComponent *sender, std::string mes)
{
    if(mes == "OpenDoorCondition")
    {
        if(player->getSecondAttribute() == readData->getConditionHiddenDoors())
            reactOnCell();
    }
    else if(mes == "addPoint")
        reactOnPlayer(ADD_Point);
    else if(mes == "removePoint")
        reactOnPlayer(DELETE_POINT);
    else if(mes == "destroyPlayer")
        reactOnPlayer(DESTROY_PLAYER);
}

void GameMediator::reactOnPlayer(ReactType type)
{
    switch (type) {
    case ADD_Point:
        player->setSecondAttribute(player->getSecondAttribute() + 1);
        break;
    case DELETE_POINT:
        player->setSecondAttribute(player->getSecondAttribute() - 1);
        break;
    case DESTROY_PLAYER:
        player->setFirstAttribute(0);
    default:
        break;
    }
}

void GameMediator::reactOnCell()
{
    field->sendCignal(OPEN_SUBLEVEL);
}
