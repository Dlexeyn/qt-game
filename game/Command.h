#ifndef COMMAND_H
#define COMMAND_H

#include "qnamespace.h"
#include <string>
#include <map>
#include <vector>

const int NUM_KEYS = 9;

enum class Commands{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    PAUSE,
    SAVE,
    NEW_GAME,
    EXIT_GAME,
    MENU
};

class CommandsHelper{
    typedef Commands T;
public:
    T commandFromString(const std::string value);
    char easytolower(char sym);
    std::string tolower(const std::string &tolower);
private:
    std::map<std::string, T> enumStringsMap = {
        { "up", T::UP },
        { "down", T::DOWN },
        { "left", T::LEFT },
        { "right", T::RIGHT },
        { "pause", T::PAUSE },
        { "save" , T::SAVE },
        { "new_game", T::NEW_GAME },
        { "exit_game", T::EXIT_GAME },
        { "menu", T::MENU }};
};

inline CommandsHelper::T CommandsHelper::commandFromString(const std::string value)
{
    return enumStringsMap[value];
}

inline char CommandsHelper::easytolower(char sym){
    if(sym<='Z' && sym>='A')
        return sym-('Z'-'z');
    return sym;
}

inline std::string CommandsHelper::tolower(const std::string &tolower)
{
    std::string temp = tolower;
    for (size_t i=0; i < temp.length(); ++i)
        temp[i] = easytolower(temp[i]);
    return temp;
}

#endif // COMMAND_H
