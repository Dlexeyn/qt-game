#include "CareTaker.hpp"
#include "map/Memento/Memento.hpp"
#include "map/Memento/SnapshotException.h"

CareTaker::CareTaker(std::vector<Memento *> snapshots,
                     const std::vector<EventSubscriber *> &loggers)
{
    this->snapshots = snapshots;
    subscribe(loggers);
}

void CareTaker::backup(int level)
{
    int num = int(snapshots.size());

    if(num >= 5)
        return;

    Memento *newMem = originator->save();
    newMem->setInfo(std::to_string(level), "Level " + std::to_string(level));
    snapshots.push_back(newMem);
}

void CareTaker::deleteBackup(int index)
{
    index--;
    auto iter = snapshots.cbegin();
    snapshots.erase(iter + index);
}

int CareTaker::undo(int index)
{
    if(!snapshots.size())
        return -1;
    Memento *memento = snapshots[index-1];
    originator->restore(memento);
    curLevel = std::stoi(memento->num());
    return curLevel;
}

void CareTaker::saveToFile()
{
    for(std::size_t i = 0; i < snapshots.size(); i++)
    {
        try {
            snapshots[i]->saveToFile(int(i));
        } catch (SnapshotException &e) {
            notifySubscribers(std::string(e.what()), "critical");
        }
    }
}

void CareTaker::setOriginator(Originator *newOriginator)
{
    originator = newOriginator;
}

std::vector<std::string> CareTaker::getInfo()
{
    std::vector<std::string> info;
    if(snapshots.size())
    {
        for(auto &s : snapshots)
            info.push_back(s->GetName()
                           + " " + s->GetTime());
    }

    return info;
}

int CareTaker::getSIZE()
{
    return SIZE;
}


