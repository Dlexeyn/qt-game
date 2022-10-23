#ifndef CONSOLELOGDECORATOR_H
#define CONSOLELOGDECORATOR_H

#include "LogDecorator.h"
#include <iostream>

class ConsoleLogDecorator : public LogDecorator
{
public:
    using LogDecorator::LogDecorator;
    Log::Message *sendMessage();
};

#endif // CONSOLELOGDECORATOR_H
