#include "LogArgs.h"

ArgsLog LogArgs::getType() const
{
    return type;
}

int *LogArgs::getArg1() const
{
    return arg1;
}

int *LogArgs::getArg2() const
{
    return arg2;
}
