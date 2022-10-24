#include "CellEventFactory.h"

CellEventFactory::CellEventFactory(const CellEventFactory& otherFactory)
{
    currentType = otherFactory.currentType;
    loggers = otherFactory.loggers;
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
        return new ColorBoxEvent(loggers, object);
        break;
    case RETURN_COLOR:
        return new ReturnColorEvent(loggers, object);
    case HIDDEN_DOOR:
        return new DeleteObjectEvent(loggers, object);
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
