#include "CellEventFactory.h"
#include "ReturnColorEvent.h"
#include "ColorBoxEvent.h"
#include "HiddenDoorEvent.h"
#include "DestroyPlayerEvent.h"

CellEventFactory::CellEventFactory(const CellEventFactory& otherFactory)
{
    currentType = otherFactory.currentType;
    loggers = otherFactory.loggers;
    player = otherFactory.player;
    object = otherFactory.object;
}

CellEventFactory::CellEventFactory(CellEventFactory &&otherFactory)
{
    std::swap(currentType, otherFactory.currentType);
    std::swap(loggers, otherFactory.loggers);
    std::swap(object, otherFactory.object);
}

Event *CellEventFactory::createEvent()
{
    switch (currentType) {
    case COLOR_BOX:
        return new ColorBoxEvent(loggers, object, player);
        break;
    case RETURN_COLOR:
        return new ReturnColorEvent(loggers, object, player);
    case HIDDEN_DOOR:
        return new DeleteObjectEvent(loggers, object);
    case DESTROY_PLAYER:
        return new DestroyPlayerEvent(loggers, object, player);
    default:
        return nullptr;
        break;
    }
}

void CellEventFactory::setCurrentType(CellEventType newCurrentType, Cell *newObject)
{
    currentType = newCurrentType;
    object = newObject;
}

void CellEventFactory::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}
