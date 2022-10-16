#include "ObjectEventFactory.h"

Event *ObjectEventFactory::createEvent()
{
    switch (currentType) {
    case COLOR_BOX:
        return new ColorBoxEvent(object);
        break;
    case RETURN_COLOR:
        return new ReturnColorEvent(object);
    case HIDDEN_DOOR:
        return new DeleteObjectEvent(object);
    case DESTROY_PLAYER:
        return new DestroyPlayer(object);
    default:
        return nullptr;
        break;
    }
}

void ObjectEventFactory::setCurrentType(ObjectEventType newCurrentType, MapObject *newObject)
{
    currentType = newCurrentType;
    object = newObject;
}
