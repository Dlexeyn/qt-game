#include "RestartEvent.h"

void RestartEvent::trigger()
{
    baseWindow->callLoseEventDialog();
    baseWindow->callRestartEventDialog(false);
}
