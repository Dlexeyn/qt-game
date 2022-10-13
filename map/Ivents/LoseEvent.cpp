#include "LoseEvent.h"

void LoseEvent::trigger()
{
    baseWindow->callExitDialog();
}
