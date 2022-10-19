#ifndef OBJECTEVENTFACTORY_H
#define OBJECTEVENTFACTORY_H


#include "EventFactory.h"
#include "ObjectEvent.h"
#include "ReturnColorEvent.h"
#include "ColorBoxEvent.h"
#include "HiddenDoorEvent.h"
#include "DestroyPlayer.h"


class ObjectEventFactory : public EventFactory
{
public:

    enum ObjectEventType
    {
        RETURN_COLOR,
        COLOR_BOX,
        HIDDEN_DOOR,
        DESTROY_PLAYER
    };

    ObjectEventFactory(ObjectEventType type): currentType(type){}
    Event* createEvent();
    void setCurrentType(ObjectEventType newCurrentType, MapObject *object);

private:
    ObjectEventType currentType;
    MapObject *object = nullptr;
};

#endif // OBJECTEVENTFACTORY_H
