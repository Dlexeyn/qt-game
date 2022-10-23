#ifndef LOGGER_H
#define LOGGER_H

#include "LogManager.h"

namespace Log
{

class Logger : public EventSubscriber
{
public:
    Logger();
    ~Logger();
    void generateMessage(Type type, std::string mes);

private:
    LogManager *logManager = nullptr;
};
}




#endif // LOGGER_H
