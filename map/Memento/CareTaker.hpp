#ifndef CARETAKER_HPP
#define CARETAKER_HPP

#include "log/EventSubscriber.h"
#include "log/LogObject.h"
#include "map/Memento/Originator.hpp"
#include <vector>

class CareTaker: public LogObject
{

public:
    CareTaker(Originator *originator)
        : originator(originator) {}

    CareTaker(const std::vector< Log::EventSubscriber* >& loggers);

    bool backup(int level);
    void deleteBackup(int index);
    void deleteAll();

    int undo(int index);

    void saveToFile();
    void recreate();

    void setOriginator(Originator *newOriginator);
    void unsetOriginator() { originator = nullptr; }

    std::vector<std::string> getInfo();

    static int getSIZE();

private:
    std::vector<Memento*> snapshots;
    Originator *originator = nullptr;
    static const int SIZE = 5;
    int curLevel = 0;

    void clearOldSaves();
};

#endif // CARETAKER_HPP
