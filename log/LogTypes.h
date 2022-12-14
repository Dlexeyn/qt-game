#ifndef LOGTYPES_H
#define LOGTYPES_H

namespace Log
{

enum class Type
{
    ObjectState,
    GlobalState,
    CriticalState
};

enum class ArgsLog{
    XY,
    SIZE_WH,
    SIZE,
    LEVEL,
    COUNT
};

}
#endif // LOGTYPES_H
