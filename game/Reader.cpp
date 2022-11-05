#include "Reader.h"

const std::map<Commands, int> &Reader::getDataForDialogs() const
{
    return dataForDialogs;
}

const std::map<int, Commands> &Reader::getDataForController() const
{
    return dataForController;
}

void Reader::sendError(int flag)
{
    if(flag)    // Используем значения по умолчанию
    {
        notifySubscribers("The File Commands.txt does not exist or incorrectly describeds ",
                          "warning", new LogArgs(ArgsLog::COUNT, flag));
        dataForController.clear();
        dataForDialogs.clear();

        dataForDialogs.insert(DefaultDataForController.begin(), DefaultDataForController.end());
        for (std::map<Commands, int>::iterator it = dataForDialogs.begin(); it != dataForDialogs.end(); ++it)
            dataForController.insert(std::pair<int, Commands>(it->second, it->first));
    }
}
