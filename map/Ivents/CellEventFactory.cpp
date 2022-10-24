#include "CellEventFactory.h"

CellEventFactory::CellEventFactory(const CellEventFactory& otherFactory)
{
    currentType = otherFactory.currentType;
    logger = otherFactory.logger;
    object = otherFactory.object;
}

CellEventFactory::CellEventFactory(CellEventFactory &&otherFactory)
{
    std::swap(currentType, otherFactory.currentType);
    std::swap(logger, otherFactory.logger);
    std::swap(object, otherFactory.object);
}

Event *CellEventFactory::createEvent()
{
    switch (currentType) {
    case COLOR_BOX:
        return new ColorBoxEvent(logger, object);
        break;
    case RETURN_COLOR:
        return new ReturnColorEvent(logger, object);
    case HIDDEN_DOOR:
        return new DeleteObjectEvent(logger, object);
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
