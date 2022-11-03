#include "GLMessage.h"
#include <algorithm>

GLMessage::GLMessage(Sender sender, ArgsTypes type, int arg)
    : sender(sender)
{
    args.push_back(arg);
    types.push_back(type);
    size = 1;
}

void GLMessage::addArg(ArgsTypes type, int arg)
{
    args.push_back(arg);
    types.push_back(type);
    size++;
}


Sender GLMessage::getSender() const
{
    return sender;
}

int GLMessage::getArg(ArgsTypes key)
{
    std::vector<ArgsTypes>::iterator iter = std::find(types.begin(), types.end(), key);
    size_t index = std::distance(types.begin(), iter);
    if(index == types.size())
        return -1; // no found
    return args.at(index);
}

ArgsTypes GLMessage::getType(int arg)
{
    std::vector<int>::iterator iter = std::find(args.begin(), args.end(), arg);
    size_t index = std::distance(args.begin(), iter);
    if(index == args.size())
        return ArgsTypes::NONE; // no found
    return types.at(index);
}


GLMessage::~GLMessage()
{

}

int GLMessage::getSize() const
{
    return size;
}

void GLMessage::setSender(Sender newSender)
{
    sender = newSender;
}
