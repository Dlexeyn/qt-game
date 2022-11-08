#include "VictoryEvent.h"

void VictoryEvent::trigger()
{
    baseWindow->callVictoryEventDialog();
    baseWindow->setStatus(WindowStatus::END_LEVEL);
    //baseWindow->setEnd(true);
}
