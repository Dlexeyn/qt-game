#include "ObjectEventFactory.h"

Event *ObjectEventFactory::createEvent()
{
    switch (currentType) {
    case COLOR_BOX:
        return new ColorBoxEvent();
        break;
    case RETURN_COLOR:
        return new ReturnColorEvent();
    case HIDDEN_DOOR:
        return new DeleteObjectEvent();
    case DESTROY_PLAYER:
        return new DestroyPlayer();
    default:
        return nullptr;
        break;
    }
}

void ObjectEventFactory::setCurrentType(ObjectEventType newCurrentType)
{
    currentType = newCurrentType;
}
