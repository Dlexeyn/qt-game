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
    this->type = type;
}


namespace Log {
Type Message::getType() const
{
    return type;
}

void Message::addText(std::string str)
{
    message += str;
}

void Message::setMessage(const std::string &newMessage)
{
    message = newMessage;
}

std::string Message::getMessage() const
{
    return message;
}

}

