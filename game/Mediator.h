#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "string"

class MapComponent;
class Mediator
{
public:
    virtual void notify(MapComponent *sender, std::string mes = "") = 0;
};

#endif // MEDIATOR_H
