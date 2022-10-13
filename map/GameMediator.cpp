#include "GameMediator.h"
#include <QDebug>

GameMediator::GameMediator(MapComponent *field, MapComponent *player, LevelReader *lvlReader)
: field(field), player(player), lvlReader(lvlReader)
{
    objectEventFactory = new ObjectEventFactory(ObjectEventFactory::COLOR_BOX);
    colorBox = objectEventFactory->createEvent();

    dynamic_cast<ObjectEventFactory*>(objectEventFactory)->setCurrentType(ObjectEventFactory::RETURN_COLOR);
    returnColor = objectEventFactory->createEvent();


    dynamic_cast<ObjectEventFactory*>(objectEventFactory)->setCurrentType(ObjectEventFactory::HIDDEN_DOOR);
    hiddenDoors = objectEventFactory->createEvent();
    dynamic_cast<ObjectEvent*>(hiddenDoors)->setObject(
                dynamic_cast<Field*>(field)->getCell(lvlReader->getHidDoorXY().y(), lvlReader->getHidDoorXY().x()));

    dynamic_cast<ObjectEventFactory*>(objectEventFactory)->setCurrentType(ObjectEventFactory::DESTROY_PLAYER);
    destroyPlayer = objectEventFactory->createEvent();

}

void GameMediator::notify(MapComponent *sender, std::string mes)
{

    if(mes == "Cell")
    {
        curCell = sender;
        if(dynamic_cast<CellSpace::Cell*>(curCell)->getCell_type() == CellSpace::TARGET_WITH_BOX)
        {
            dynamic_cast<ObjectEvent*>(returnColor)->setObject(curCell);
            returnColor->trigger();
            reactOnPlayer(DELETE_POINT);
        }
        if(dynamic_cast<CellSpace::Cell*>(curCell)->getCell_type() == CellSpace::END_CELL)
        {
            dynamic_cast<ObjectEvent*>(destroyPlayer)->setObject(player);
            destroyPlayer->trigger();
        }
    }
    else if(mes == "Box")
    {
        curBox = sender;
        if(dynamic_cast<CellSpace::Cell*>(curCell)->getCell_type() == CellSpace::TARGET_BOX)
        {

            dynamic_cast<ObjectEvent*>(colorBox)->setObject(curCell);
            colorBox->trigger();
            reactOnPlayer(ADD_Point);

            if(dynamic_cast<Player*>(player)->getVictoryPoints() == lvlReader->getConditionHiddenDoors())
            {
                hiddenDoors->trigger();
                delete hiddenDoors;
                hiddenDoors = nullptr;
            }
        }
    }
}


void GameMediator::setField(Field *newField)
{
    field = newField;
}

void GameMediator::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}

void GameMediator::reactOnPlayer(ReactType type)
{
    switch (type) {
    case ADD_Point:
        dynamic_cast<Player*>(player)->addVictoryPoint();
        break;
    case DELETE_POINT:
        dynamic_cast<Player*>(player)->deleteVictoryPoint();
        break;
    default:
        break;
    }
}
