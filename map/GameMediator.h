#ifndef GAMEMEDIATOR_H
#define GAMEMEDIATOR_H

#include <game/Mediator.h>
#include "map/Ivents/Event.h"
#include "map/ReadData.h"
#include "map/MapComponent.h"


enum ReactType{
    ADD_Point = 1,
    DELETE_POINT = 2,
    OPEN_SUBLEVEL = 3,
    DESTROY_PLAYER = 4
};

class GameMediator : public Mediator
{
public:
    GameMediator(MapComponent *field, MapComponent *player,  std::vector <MapComponent*> &listBox, ReadData *readData);
    void notify(std::string mes = "");

    void reactOnCell();

    void reactOnPlayer(ReactType type);

private:
    MapComponent *field = nullptr;
    MapComponent *player = nullptr;
    std::vector <MapComponent*> listBox;

    ReadData *readData = nullptr;

    //ObjectEventFactory *objectEventFactory = nullptr;

    Event *colorBox = nullptr;
    Event *returnColor = nullptr;
    Event *hiddenDoors = nullptr;
    Event *destroyPlayer = nullptr;
};

#endif // GAMEMEDIATOR_H
