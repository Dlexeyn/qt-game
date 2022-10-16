#include "GameMediator.h"
#include <QDebug>

GameMediator::GameMediator(MapComponent *field, MapComponent *player, LevelReader *lvlReader)
: field(field), player(player), lvlReader(lvlReader)
{
    objectEventFactory = new ObjectEventFactory(ObjectEventFactory::COLOR_BOX);
//    colorBox = objectEventFactory->createEvent();

//    objectEventFactory->setCurrentType(ObjectEventFactory::RETURN_COLOR);
//    returnColor = objectEventFactory->createEvent();

//    objectEventFactory->setCurrentType(ObjectEventFactory::HIDDEN_DOOR);
//    hiddenDoors = objectEventFactory->createEvent();
//    dynamic_cast<ObjectEvent*>(hiddenDoors)->setObject(
//                dynamic_cast<Field*>(field)->getCell(lvlReader->getHidDoorXY().y(), lvlReader->getHidDoorXY().x()));

//    objectEventFactory->setCurrentType(ObjectEventFactory::DESTROY_PLAYER);
//    destroyPlayer = objectEventFactory->createEvent();

}

void GameMediator::notify(MapComponent *sender, std::string mes)
{
    if(mes == "returnColor")
    {
        objectEventFactory->setCurrentType(ObjectEventFactory::RETURN_COLOR, sender);
        sender->setEvent(objectEventFactory->createEvent());
        reactOnPlayer(ADD_Point);
    }
    else if(mes == "colorBox")
    {
        objectEventFactory->setCurrentType(ObjectEventFactory::COLOR_BOX, sender);
        sender->setEvent(objectEventFactory->createEvent());
        reactOnPlayer(DELETE_POINT);
    }
    else if(mes == "isOpenSublevel")
    {
        if(player->getSecondAttribute() == lvlReader->getConditionHiddenDoors())
            reactOnCell(OPEN_SUBLEVEL, sender);
    }
    else if(mes == "destroyPlayer")
    {
        objectEventFactory->setCurrentType(ObjectEventFactory::DESTROY_PLAYER, player);
        sender->setEvent(objectEventFactory->createEvent());
        reactOnCell(IMPACT_ON_PLAYER, sender);
    }

//    if(mes == "Cell")
//    {
//        curCell = sender;
//        if(dynamic_cast<CellSpace::Cell*>(curCell)->getCell_type() == CellSpace::TARGET_WITH_BOX)
//        {
//            dynamic_cast<ObjectEvent*>(returnColor)->setObject(curCell);
//            returnColor->trigger();
//            reactOnPlayer(DELETE_POINT);
//        }
//        if(dynamic_cast<CellSpace::Cell*>(curCell)->getCell_type() == CellSpace::END_CELL)
//        {
//            dynamic_cast<ObjectEvent*>(destroyPlayer)->setObject(player);
//            destroyPlayer->trigger();
//        }
//    }
//    else if(mes == "Box")
//    {
//        curBox = sender;
//        if(dynamic_cast<CellSpace::Cell*>(curCell)->getCell_type() == CellSpace::TARGET_BOX)
//        {

//            dynamic_cast<ObjectEvent*>(colorBox)->setObject(curCell);
//            colorBox->trigger();
//            reactOnPlayer(ADD_Point);

//            if(dynamic_cast<Player*>(player)->getVictoryPoints() == lvlReader->getConditionHiddenDoors())
//            {
//                hiddenDoors->trigger();
//                delete hiddenDoors;
//                hiddenDoors = nullptr;
//            }
//        }
//    }
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
        player->setSecondAttribute(player->getSecondAttribute() + 1);
        break;
    case DELETE_POINT:
        player->setSecondAttribute(player->getSecondAttribute() - 1);
        break;
    default:
        break;
    }
}

void GameMediator::reactOnCell(ReactType type, MapComponent *cell)
{
    switch (type) {
    case OPEN_SUBLEVEL:
        cell->sendCignal(CellSpace::CONDITION_IS_TRUE);
        break;
    case IMPACT_ON_PLAYER:
        cell->sendCignal(CellSpace::RANDOM_EVENT);
        break;
    default:
        break;
    }
}
