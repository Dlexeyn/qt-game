#ifndef GLOBALMEDIATOR_H
#define GLOBALMEDIATOR_H

#include <string>

class GlobalComponent;
class GlobalMediator
{
public:
    virtual void notify(GlobalComponent *sender, std::string mes = "") = 0;
};

#endif // GLOBALMEDIATOR_H
