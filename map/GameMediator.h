#ifndef GAMEMEDIATOR_H
#define GAMEMEDIATOR_H

#include <game/Mediator.h>
#include "map/Ivents/Event.h"
#include "map/Ivents/EventFactory.h"
#include "map/Ivents/GlobalEventFactory.h"
#include "map/Ivents/ObjectEventFactory.h"
#include "map/LevelReader.h"
#include "map/MapComponent.h"
#include "map/Box.h"
#include "map/Cell.h"
#include "map/Field.h"
#include "objects/Player.h"

enum ReactType{
    ADD_Point,
    DELETE_POINT,
    OPEN_SUBLEVEL,
    IMPACT_ON_PLAYER
};

class GameMediator : public Mediator
{
public:
    GameMediator(MapComponent *field, MapComponent *player, LevelReader *lvlReader);
    void notify(MapComponent *sender, std::string mes = "");

    void reactOnCell();

    void setField(Field *newField);

    void setPlayer(Player *newPlayer);

    void reactOnPlayer(ReactType type);

    void reactOnCell(ReactType type, MapComponent *cell);

private:
    MapComponent *field = nullptr;
    MapComponent *player = nullptr;
    MapComponent *curBox = nullptr;
    MapComponent *curCell = nullptr;

    LevelReader *lvlReader = nullptr;

    ObjectEventFactory *objectEventFactory = nullptr;

    Event *colorBox = nullptr;
    Event *returnColor = nullptr;
    Event *hiddenDoors = nullptr;
    Event *destroyPlayer = nullptr;
};

#endif // GAMEMEDIATOR_H
