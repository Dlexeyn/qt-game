#include "LoseEvent.h"

void LoseEvent::trigger()
{
    baseWindow->callLoseDialog();
    baseWindow->setEnd(true);
}
