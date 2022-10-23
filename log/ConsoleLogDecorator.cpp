#include "ConsoleLogDecorator.h"


Log::Message *ConsoleLogDecorator::sendMessage()
{
    Log::Message *mes = logSource->sendMessage();
    std::cout << mes << "\n";
    return mes;
}
