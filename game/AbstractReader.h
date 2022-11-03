#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include <map>
#include "Command.h"

class AbstractReader
{
public:
    virtual int readCommands() = 0;
};

#endif // ABSTRACTREADER_H
