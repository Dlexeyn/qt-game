#include "Message.h"

Log::Message::Message(Type type, std::string str)
{
    switch (type) {
    case Log::Type::ObjectState:
        message = "{object} ";
        break;
    case Log::Type::GlobalState:
        message = "{global} ";
        break;
    case Log::Type::CriticalState:
        message = "{critical} ";
        break;
    default:
        break;
    }
    message += str;
}
