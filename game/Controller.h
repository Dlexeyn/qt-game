#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Qt>
#include <map>
#include "GlobalComponent.h"
#include "Command.h"

class Controller: public GlobalComponent
{
public:
    Controller(const std::map <int, Commands> KeyCommands) :
        KeyCommands(std::map(KeyCommands))
    {
//        subscribe(loggers);
//        reader = new CommandReader(&KeyCommands);
//        int flag = reader->readCommands();
//        if(flag > 0)
//            notifySubscribers("The File Commands.txt does not exist or incorrectly describeds ",
//                              "warning", new LogArgs(ArgsLog::COUNT, flag));
    }

    enum commands{
        UP = Qt::Key_W,
        DOWN = Qt::Key_S,
        LEFT = Qt::Key_A,
        RIGHT = Qt::Key_D
    };

    void getMessage(GLMessage *mes);


    const std::map<int, Commands> &getKeyCommands() const;

private:
    void sendCommand(Commands command);

    bool getMoveArgs(const Commands command, std::vector<int> &args, std::vector<ArgsTypes> &types);
    void getOtherArgs(const Commands command, std::vector<int> &args, std::vector<ArgsTypes> &types);
    std::map <int, Commands> KeyCommands;
};

#endif // CONTROLLER_H
