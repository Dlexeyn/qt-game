#include "LoseEvent.h"

void LoseEvent::trigger()
{
    baseWindow->callLoseEventDialog();
    baseWindow->setStatus(WindowStatus::END_LEVEL);
    //baseWindow->setEnd(true);
}
