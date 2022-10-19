#ifndef CELLEVENTFACTORY_H
#define CELLEVENTFACTORY_H


#include "EventFactory.h"
#include "CellEvent.h"
#include "ReturnColorEvent.h"
#include "ColorBoxEvent.h"
#include "HiddenDoorEvent.h"


class CellEventFactory : public EventFactory
{
public:

    enum CellEventType
    {
        RETURN_COLOR,
        COLOR_BOX,
        HIDDEN_DOOR,
        DESTROY_PLAYER
    };

    CellEventFactory(CellEventType type): currentType(type){}
    Event* createEvent();
    void setCurrentType(CellEventType newCurrentType, Cell *object);

private:
    CellEventType currentType;
    Cell *object = nullptr;
};

#endif // CELLEVENTFACTORY_H
