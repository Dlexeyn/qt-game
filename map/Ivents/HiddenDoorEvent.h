#ifndef HIDDENDOOREVENT_H
#define HIDDENDOOREVENT_H

#include "ObjectEvent.h"

class DeleteObjectEvent : public ObjectEvent
{
public:
    DeleteObjectEvent();
    void trigger();
};

#endif // HIDDENDOOREVENT_H
