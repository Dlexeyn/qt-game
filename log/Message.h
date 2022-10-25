#ifndef MESSAGE_H
#define MESSAGE_H

#include "LogTypes.h"
#include <string>
#include <fstream>

namespace Log
{
class Message
{
public:
    Message(Type type, std::string str);

    friend std::ostream& operator<<(std::ostream& out, Message* mes)
    {
        out << mes->message;
        return out;
    }

    Type getType() const;

private:
    std::string message;
    Type type;

};
}


#endif // MESSAGE_H
