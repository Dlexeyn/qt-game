#ifndef LOGPOOL_H
#define LOGPOOL_H
#include <vector>
#include "log/GlobalLogger.h"
#include "log/StateLogger.h"
#include "log/ObjectLogger.h"

class LogPool
{
public:
    LogPool(Config::AppConfigurator *config);
    ~LogPool();
    const std::vector<EventSubscriber *> &getLoggers() const;
    //Config::AppConfigurator *getConfig() const;

    LogManager *getLogManager() const;

private:
    LogManager *logManager = nullptr;
    Config::AppConfigurator *config = nullptr;
    std::vector< EventSubscriber* > loggers;

};

#endif // LOGPOOL_H
