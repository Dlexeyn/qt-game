#include "Controller.h"
#include "graphics/BaseWindowStatus.h"

void Controller::sendCommand(Commands command)
{
    std::vector<int> args = { 0 };
    std::vector<ArgsTypes> types;
    GLMessage newMes(Sender::CONTROLLER_PLAYER);

    if(!getMoveArgs(command, args, types))
    {
        getOtherArgs(command, args, types);
        newMes.setSender(Sender::CONTROLLER_GAME);
    }

    for(size_t index = 0; index < args.size(); index++)
        newMes.addArg(types[index], args[index]);
    game->notify(&newMes);

}

bool Controller::getMoveArgs(const Commands command, std::vector<int> &args, std::vector<ArgsTypes> &types)
{
    switch (command) {
    case Commands::UP:
        args.push_back(-1);
        types.insert(types.cend(), {ArgsTypes::X, ArgsTypes::Y});
        break;
    case Commands::DOWN:
        args.push_back(1);
        types.insert(types.cend(), {ArgsTypes::X, ArgsTypes::Y});
        break;
    case Commands::LEFT:
        args.insert(args.cbegin(), -1);
        types.insert(types.cend(), {ArgsTypes::X, ArgsTypes::Y});
        break;
    case Commands::RIGHT:
        args.insert(args.cbegin(), 1);
        types.insert(types.cend(), {ArgsTypes::X, ArgsTypes::Y});
        break;
    default:
        return false;
    }
    return true;
}

void Controller::getOtherArgs(const Commands command, std::vector<int> &args, std::vector<ArgsTypes> &types)
{
    types.push_back(ArgsTypes::STATUS);
    switch (command) {
    case Commands::PAUSE:
        args[0] = int(WindowStatus::PAUSE);
        break;
    case Commands::SAVE:
        args[0] = int(WindowStatus::isSAVE);
        break;
    case Commands::NEW_GAME:
        args[0] = int(WindowStatus::isRestart);
        break;
    case Commands::EXIT_GAME:
        args[0] = int(WindowStatus::isEXIT);
        break;
    case Commands::MENU:
        args[0] = int(WindowStatus::MENU);
        break;
    case Commands::LOAD:
        args[0] = int(WindowStatus::isLOAD);
        break;
    default:
        break;
    }
}

void Controller::getMessage(GLMessage* mes)
{
    int key = mes->getArg(ArgsTypes::KEY);
    std::map <int, Commands>:: iterator it = KeyCommands.find(key);
    if(it != KeyCommands.end())
        sendCommand(KeyCommands.at(key));
}
