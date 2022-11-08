#include "ExitEvent.h"

void ExitEvent::trigger()
{
    baseWindow->callLoseEventDialog();
}
