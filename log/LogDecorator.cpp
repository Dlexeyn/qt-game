#include "LogDecorator.h"

Log::Message *LogDecorator::writeMes(Log::Message *data)
{
    return logSource->writeMes(data);
}
