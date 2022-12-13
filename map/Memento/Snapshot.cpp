#include "Snapshot.h"
#include <iomanip>
#include <ctime>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <cstdio>

Snapshot::Snapshot(const std::vector<EventSubscriber *> &loggers)
{
    name = "Level ";
    subscribe(loggers);
}

Snapshot::Snapshot(const std::vector<std::vector<CellSpace::Cell *> > &map_field,
                   const int &map_height,
                   const int &map_width,
                   const QPoint *hidDoor,
                   const Player &player,
                   const std::vector<Box *> &BoxList,
                   const int &condition,
                   const int &victory)
{
    state["HEIGHT"].push_back(map_height);
    state["WIDTH"].push_back(map_width);
    state["HIDDOR_CONDITION"].push_back(condition);
    state["VICTORY_CONDITION"].push_back(victory);

    state["PLAYER_MAX_H"].push_back(player.getMaxHealth());
    state["PLAYER_CUR_H"].push_back(player.getCurHealth());
    state["PLAYER_POINTS"].push_back(player.getVictoryPoints());
    state["PLAYER_XY"].push_back(player.getPos(true));
    state["PLAYER_XY"].push_back(player.getPos(false));

    if(hidDoor)
    {
        state["HIDDOR_XY"].push_back(hidDoor->x());
        state["HIDDOR_XY"].push_back(hidDoor->y());
    }
    else
    {
        state["HIDDOR_XY"].push_back(0);
        state["HIDDOR_XY"].push_back(0);
    }

    state["BOX_COUNT"].push_back(BoxList.size());
    for(size_t i = 0; i < BoxList.size(); i++)
    {
        state["BOX_" + std::to_string(i)].push_back(BoxList[i]->getPos(true));
        state["BOX_" + std::to_string(i)].push_back(BoxList[i]->getPos(false));
    }

    for(int y = 0; y < map_height; y++)
        for(int x = 0; x < map_width; x++)
            state["MAP_" + std::to_string(y)].push_back(map_field[y][x]->getCell_type());


    auto time = std::time(nullptr);
    auto localTime = *std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(&localTime, "%H:%M:%S");
    time_ = oss.str();
}

Snapshot::~Snapshot()
{

}

std::map<std::string, std::vector<int> > Snapshot::GetState() const
{
    return state;
}

void Snapshot::setInfo(std::string num, std::string name)
{
    num_ = num;
    this->name = name;
}

bool Snapshot::saveToFile(int index)
{
    clearOldSaves();
    writer = new SnapshotWriter(std::to_string(index));
    bool var = writer->write(state, time_, num_);
    delete writer;
    return var;
}

bool Snapshot::readFromFile(int index)
{
    reader = new SnapshotReader(std::to_string(index));
    bool var;
    try {
        var = reader->read();
    } catch (SnapshotException &e) {
        notifySubscribers(std::string(e.what()), "warning");
        var = false;
    }

    if(var)
    {
        state = reader->getState();
        time_ = std::to_string(state["TIME"][0]);
        time_.insert(2, 1, ':');
        time_.insert(5, 1, ':');
        name += std::to_string(state["LEVEL"][0]);
        num_ = std::to_string(state["LEVEL"][0]);
        state.erase("TIME");
        state.erase("LEVEL");
    }
    delete reader;
    return var;
}

void Snapshot::clearOldSaves()
{
    for(int i = 0; i < SIZE; i++)
    {
        std::string name = "save_" + std::to_string(i) + ".txt";
        if(std::filesystem::exists(name))
            std::remove(name.c_str());
    }
}





