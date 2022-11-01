#include "GLMessage.h"

GLMessage::GLMessage(Sender sender, ArgsTypes type, int arg)
    : sender(sender)
{
    args[type] = arg;
}

void GLMessage::addArg(ArgsTypes type, int arg)
{
    args[type] = arg;
}


Sender GLMessage::getSender() const
{
    return sender;
}

int GLMessage::getArg(ArgsTypes key)
{
    return args[key];
}


GLMessage::~GLMessage()
{

}
