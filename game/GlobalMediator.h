#ifndef GLOBALMEDIATOR_H
#define GLOBALMEDIATOR_H

#include <string>
#include "GLMessage.h"

class GlobalComponent;
class GlobalMediator
{
public:
    virtual void notify(GLMessage *mes) = 0;
    virtual ~GlobalMediator() = default;
};

#endif // GLOBALMEDIATOR_H
