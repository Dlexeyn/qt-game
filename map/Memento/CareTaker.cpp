#include "CareTaker.hpp"
#include "map/Memento/Memento.hpp"
#include "map/Memento/SaveFileException.h"
#include "map/Memento/SnapshotException.h"
#include "map/Memento/Snapshot.h"
#include <filesystem>

CareTaker::CareTaker(const std::vector<EventSubscriber *> &loggers)
{
    subscribe(loggers);
}

bool CareTaker::backup(int level)
{
    int num = int(snapshots.size());

    if(num >= 5)
        return false;

    Memento *newMem = originator->save();
    newMem->setInfo(std::to_string(level), "Level " + std::to_string(level));
    snapshots.push_back(newMem);
    return true;
}

void CareTaker::deleteBackup(int index)
{
    index--;
    auto iter = snapshots.cbegin();
    snapshots.erase(iter + index);
}

void CareTaker::deleteAll()
{
    for(auto s: snapshots)
        delete s;
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
    clearOldSaves();
    for(std::size_t i = 0; i < snapshots.size(); i++)
    {
        try {
            snapshots[i]->saveToFile(int(i));
        } catch (SnapshotException &e) {
            notifySubscribers(std::string(e.what()), "critical");
        }
    }
}

void CareTaker::recreate()
{
    for(int i = 0; i < SIZE; i++)
    {
        try {
            Snapshot *s = new Snapshot();
            if(s->readFromFile(i))
                snapshots.push_back(s);
        } catch (SnapshotException &e) {
            notifySubscribers(std::string(e.what()), "warning");
        } catch (SaveFileException &e) {
            notifySubscribers(std::string(e.what()), "warning");
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

void CareTaker::clearOldSaves()
{
    for(int i = 0; i < SIZE; i++)
    {
        std::string name = "save_" + std::to_string(i) + ".txt";
        if(std::filesystem::exists(name))
            std::remove(name.c_str());
    }
}


