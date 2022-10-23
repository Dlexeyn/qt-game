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

private:
    std::string message;

};
}


#endif // MESSAGE_H
