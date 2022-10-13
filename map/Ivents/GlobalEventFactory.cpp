#include "GlobalEventFactory.h"

Event *GlobalEventFactory::createEvent()
{
    switch (currentType) {
    case Victory:
        return new VictoryEvent(window);
        break;
    case Lose:
        return new LoseEvent(window);
    default:
        break;
    }
}

void GlobalEventFactory::setCurrentType(GlobalEventType newCurrentType)
{
    currentType = newCurrentType;
}
