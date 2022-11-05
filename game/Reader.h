#ifndef READER_H
#define READER_H

#include "AbstractReader.h"

class Reader : public AbstractReader
{
public:
    Reader(){}
    ~Reader(){}
    const std::map<Commands, int> &getDataForDialogs() const;

    const std::map<int, Commands> &getDataForController() const;

protected:
    CommandsHelper ch;
    std::map <int, Commands> dataForController;
    std::map <Commands, int> dataForDialogs;

    std::map<Commands, int> DefaultDataForController
    {
        {Commands::UP, Qt::Key_W},
        {Commands::DOWN, Qt::Key_S},
        {Commands::LEFT, Qt::Key_A},
        {Commands::RIGHT, Qt::Key_D},
        {Commands::PAUSE, Qt::Key_P},
        {Commands::SAVE, Qt::Key_O},
        {Commands::EXIT_GAME, Qt::Key_End},
        {Commands::NEW_GAME, Qt::Key_Home},
        {Commands::MENU, Qt::Key_Escape}
    };

    void sendError(int flag);
};

#endif // READER_H
