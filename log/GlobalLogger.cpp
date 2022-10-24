#include "GlobalLogger.h"

void GlobalLogger::generateMessage(std::string type, std::string mes)
{
    if(type == "global" or type == "game")
    {
        Message *log = logManager->writeSource(new Message(Type::GlobalState, mes));
        delete log;
    }

}
