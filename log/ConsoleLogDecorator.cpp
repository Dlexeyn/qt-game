#include "ConsoleLogDecorator.h"

Log::Message *ConsoleLogDecorator::writeMes(Log::Message *data)
{
    data = logSource->writeMes(data);
    std::cout << data << "\n";
    return data;
}
