#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Qt>
#include <map>
#include "graphics/BaseWindowStatus.h"
#include "log/LogObject.h"
#include "GlobalComponent.h"
#include "Command.h"
#include "CommandReader.h"

class Controller: public GlobalComponent, public LogObject
{
public:
    Controller(const std::vector<EventSubscriber*> &loggers){
        subscribe(loggers);
        reader = new CommandReader(&KeyCommands);
        int flag = reader->readCommands();
        if(flag > 0)
            notifySubscribers("The File Commands.txt does not exist or incorrectly describeds ",
                              "warning", new LogArgs(ArgsLog::COUNT, flag));
    }

    enum commands{
        UP = Qt::Key_W,
        DOWN = Qt::Key_S,
        LEFT = Qt::Key_A,
        RIGHT = Qt::Key_D
    };

    void getMessage(GLMessage *mes);

    int &getStepX();

    int &getStepY();

private:
    int stepX, stepY;
    void sendCommand(Commands command);

    bool getMoveArgs(const Commands command, std::vector<int> &args, std::vector<ArgsTypes> &types);
    void getOtherArgs(const Commands command, std::vector<int> &args, std::vector<ArgsTypes> &types);
    AbstractReader *reader = nullptr;
    std::map <int, Commands> KeyCommands;
};

#endif // CONTROLLER_H
