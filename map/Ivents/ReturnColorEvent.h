#ifndef RETURNCOLOREVENT_H
#define RETURNCOLOREVENT_H

#include "ObjectEvent.h"

class ReturnColorEvent : public ObjectEvent
{
public:
    ReturnColorEvent();
    void trigger();
};

#endif // RETURNCOLOREVENT_H
