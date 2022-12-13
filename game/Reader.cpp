#include "Reader.h"
#include "qnamespace.h"

const std::map<int, Commands> &Reader::getData() const
{
    return data;
}

void Reader::sendError(int flag)
{
    if(flag)
    {
        notifySubscribers("The File Commands.txt does not exist or incorrectly describeds ",
                          "warning", new LogArgs(ArgsLog::COUNT, flag));

        createDefaultData();
        data.clear();

        for (std::map<int, Commands>::iterator it = DefaultData.begin(); it != DefaultData.end(); ++it)
            data.insert(std::pair<int, Commands>(it->first, it->second));   // Используем значения по умолчанию
    }
}

void Reader::createDefaultData()
{
    DefaultData = {
        {Qt::Key_W, Commands::UP},
        {Qt::Key_S, Commands::DOWN},
        {Qt::Key_A, Commands::LEFT},
        {Qt::Key_D, Commands::RIGHT},
        {Qt::Key_P, Commands::PAUSE},
        {Qt::Key_O, Commands::SAVE},
        {Qt::Key_End, Commands::EXIT_GAME},
        {Qt::Key_Home, Commands::NEW_GAME},
        {Qt::Key_Escape, Commands::MENU},
        {Qt::Key_L, Commands::LOAD}
    };
}
