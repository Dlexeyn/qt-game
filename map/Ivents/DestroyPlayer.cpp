#include "DestroyPlayer.h"

void DestroyPlayer::trigger()
{
    object->setFirstAttribute(0);
    object->changeStatus();
}
