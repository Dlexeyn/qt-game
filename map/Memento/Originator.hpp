#ifndef ORIGINATOR_HPP
#define ORIGINATOR_HPP

#include "Memento.hpp"

class Originator
{
public:
    Originator();
    virtual Memento *save() = 0;
    virtual void restore(Memento* memento) = 0;
};

#endif // ORIGINATOR_HPP
