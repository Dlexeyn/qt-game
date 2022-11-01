#ifndef LOGARGS_H
#define LOGARGS_H

#include <map>
#include "LogTypes.h"

using namespace Log;

class LogArgs
{
public:
    LogArgs(ArgsLog type, int arg1, int arg2)
        : type(type), arg1(new int(arg1)), arg2(new int(arg2)) {}
    LogArgs(ArgsLog type, int arg)
        : type(type), arg1(new int(arg)) {}

    ArgsLog getType() const;

    int *getArg1() const;

    int *getArg2() const;

private:
    ArgsLog type;
    int *arg1 = nullptr;
    int *arg2 = nullptr;
};

#endif // LOGARGS_H
