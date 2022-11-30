#include "GlobalEventFactory.h"
#include "VictoryEvent.h"
#include "RestartEvent.h"
#include "LoseEvent.h"

Event *GlobalEventFactory::createEvent()
{
    switch (currentType) {
    case Victory:
        return new VictoryEvent(window);
        break;
    case Lose:
        return new LoseEvent(window);
        break;
    case Restart:
        return new RestartEvent(window);
        break;
    }
    return nullptr;
}

void GlobalEventFactory::setCurrentType(GlobalEventType newCurrentType)
{
    currentType = newCurrentType;
}
