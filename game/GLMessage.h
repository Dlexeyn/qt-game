#ifndef GLMESSAGE_H
#define GLMESSAGE_H

#include <map>
#include "game/ArgsTypes.h"

class GLMessage
{
public:
    GLMessage(Sender sender, ArgsTypes type, int arg);

    void addArg(ArgsTypes type, int arg);

    Sender getSender() const;

    int getArg(ArgsTypes key);

    ~GLMessage();
private:
    std::map <ArgsTypes, int> args;
    Sender sender;
};
#endif // GLMESSAGE_H
