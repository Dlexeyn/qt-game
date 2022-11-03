#ifndef LOGSOURCE_H
#define LOGSOURCE_H

#include "EventSubscriber.h"
#include "Message.h"


class LogSource
{
public:
    virtual Log::Message *writeMes(Log::Message *data) = 0;
    virtual ~LogSource() = default;
};

#endif // LOGSOURCE_H
