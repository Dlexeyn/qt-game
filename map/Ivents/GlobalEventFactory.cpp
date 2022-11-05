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
    case Restart:
        break;
    }
}

void GlobalEventFactory::setCurrentType(GlobalEventType newCurrentType)
{
    currentType = newCurrentType;
}
