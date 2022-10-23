#ifndef LOGSOURCE_H
#define LOGSOURCE_H

#include "EventSubscriber.h"

class LogSource
{
public:
    virtual Log::Message *sendMessage() = 0;
    virtual void setLogSource(LogSource *newLogSource) = 0;
    virtual ~LogSource() = default;
};

#endif // LOGSOURCE_H
