#include "GameMediator.h"
#include <QDebug>

GameMediator::GameMediator(MapComponent *field, MapComponent *player, std::vector<MapComponent *> &listBox, ReadData *readData)
: field(field), player(player), listBox(listBox), readData(readData)
{

}

void GameMediator::notify(std::string mes)
{
    if(mes == "addPoint")
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
        player->setAttribute(ObjectAttribute::POINTS, player->getAttribute(ObjectAttribute::POINTS) + 1);
        player->notifySubscribers("Player : find one victory point", "object");
        if(player->getAttribute(ObjectAttribute::POINTS) == readData->getConditionHiddenDoors())
            reactOnCell();
        break;
    case DELETE_POINT:
        player->setAttribute(ObjectAttribute::POINTS, player->getAttribute(ObjectAttribute::POINTS) - 1);
        player->notifySubscribers("Player : lost one victory point", "object");
        break;
    case DESTROY_PLAYER:
        player->setAttribute(ObjectAttribute::HEALTH, 0);
        player->notifySubscribers("Player : was destroyed", "object");
    default:
        break;
    }
}

void GameMediator::reactOnCell()
{
    field->sendCignal();
}
