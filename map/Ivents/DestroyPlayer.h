#ifndef DESTROYPLAYER_H
#define DESTROYPLAYER_H

#include "ObjectEvent.h"

class DestroyPlayer : public ObjectEvent
{
public:
    DestroyPlayer();
    void trigger();
};

#endif // DESTROYPLAYER_H
