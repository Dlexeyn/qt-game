#ifndef GLOBALMEDIATOR_H
#define GLOBALMEDIATOR_H

#include <string>

class GlobalComponent;
class GlobalMediator
{
public:
    virtual void notify(std::string mes = "") = 0;
};

#endif // GLOBALMEDIATOR_H
