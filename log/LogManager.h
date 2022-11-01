#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <vector>
#include "LogData.h"
#include "log/ConsoleLogDecorator.h"
#include "log/FileLogDecorator.h"
#include "config/AppConfigurator.h"

class LogManager
{
public:
    LogManager(Config::AppConfigurator *config) : config(config) {
        source = new LogData();
    }
    ~LogManager();
    Log::Message* writeSource(Log::Message *mes);
    void initDecorators();
private:
    Config::AppConfigurator *config = nullptr;
    LogSource *source = nullptr;
    std::vector < LogSource* > decorators;

    bool messageFilter(Log::Message *mes);
    void clearDecorators();
};

#endif // LOGMANAGER_H
