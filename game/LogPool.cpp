#include "LogPool.h"

LogPool::LogPool(Config::AppConfigurator *config) : config(config)
{
    logManager = new LogManager(config);
    loggers.push_back(new GlobalLogger(logManager));
    loggers.push_back(new StateLogger(logManager));
    loggers.push_back(new ObjectLogger(logManager));
}

LogPool::~LogPool()
{
    delete logManager;
    loggers.clear();
    std::vector< EventSubscriber* >( loggers ).swap( loggers );
}

const std::vector<EventSubscriber *> &LogPool::getLoggers() const
{
    return loggers;
}

Config::AppConfigurator *LogPool::getConfig() const
{
    return config;
}
