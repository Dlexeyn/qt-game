#include "Logger.h"

Log::Logger::Logger(){
    logManager = new LogManager();
}

Log::Logger::~Logger()
{
    delete logManager;
}

void Log::Logger::generateMessage(Type type, std::string mes)
{
    Message *log = logManager->writeSource(new Message(type, mes));
    delete log;
}





