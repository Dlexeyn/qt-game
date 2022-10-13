#include "DestroyPlayer.h"

DestroyPlayer::DestroyPlayer()
{

}

void DestroyPlayer::trigger()
{
    (dynamic_cast<Player*>(object))->changeStatus();
}
