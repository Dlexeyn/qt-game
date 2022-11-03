#ifndef GLMESSAGE_H
#define GLMESSAGE_H

#include <map>
#include <vector>
#include <algorithm>
#include "game/ArgsTypes.h"

class GLMessage
{
public:
    GLMessage(Sender sender, ArgsTypes type, int arg);
    GLMessage(Sender sender) : sender(sender) { size = 0; }

    void addArg(ArgsTypes type, int arg);

    Sender getSender() const;

    int getArg(ArgsTypes key);
    ArgsTypes getType(int arg);

    ~GLMessage();
    int getSize() const;

    void setSender(Sender newSender);

private:
    std::vector <int> args;
    std::vector <ArgsTypes> types;
    int size;
    Sender sender;
};
#endif // GLMESSAGE_H
