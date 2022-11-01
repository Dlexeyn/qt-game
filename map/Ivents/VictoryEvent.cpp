#include "VictoryEvent.h"

void VictoryEvent::trigger()
{
    baseWindow->callVictoryDialog();
    baseWindow->setEnd(true);
}
