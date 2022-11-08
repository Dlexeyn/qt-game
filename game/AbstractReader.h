#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include <map>
#include "Command.h"
#include "log/LogObject.h"

class AbstractReader : public LogObject
{
public:
    virtual ~AbstractReader() = default;
    virtual void readCommands() = 0;
    virtual const std::map<int, Commands> &getData() const = 0;
    virtual void sendError(int flag) = 0;
    virtual void createDefaultData() = 0;
};

#endif // ABSTRACTREADER_H
