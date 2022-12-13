#include "Snapshot.h"
#include "SnapshotException.h"
#include <iomanip>
#include <ctime>
#include <sstream>
#include <iostream>
#include <cstdio>

Snapshot::Snapshot()
{
    name = "Level ";
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
    state["HIDDOR-CONDITION"].push_back(condition);
    state["VICTORY-CONDITION"].push_back(victory);

    state["PLAYER-MAX-H"].push_back(player.getMaxHealth());
    state["PLAYER-CUR-H"].push_back(player.getCurHealth());
    state["PLAYER-POINTS"].push_back(player.getVictoryPoints());
    state["PLAYER-XY"].push_back(player.getPos(true));
    state["PLAYER-XY"].push_back(player.getPos(false));

    if(hidDoor)
    {
        state["HIDDOR-XY"].push_back(hidDoor->x());
        state["HIDDOR-XY"].push_back(hidDoor->y());
    }
    else
    {
        state["HIDDOR-XY"].push_back(0);
        state["HIDDOR-XY"].push_back(0);
    }

    state["BOX-COUNT"].push_back(BoxList.size());
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
    writer = new SnapshotWriter(std::to_string(index));
    bool var = writer->write(state, time_, num_);
    delete writer;
    return var;
}

bool Snapshot::readFromFile(int index)
{
    reader = new SnapshotReader(std::to_string(index));
    bool var = reader->read();
    if(var)
    {
        state = reader->getState();
        checkState();

        for(auto s : state["TIME"])
            time_ += std::to_string(s);

        time_.insert(2, 1, ':');
        time_.insert(5, 1, ':');

        name += std::to_string(state["LEVEL"][0]);
        num_ = std::to_string(state["LEVEL"][0]);

        state.erase("TIME");
        state.erase("LEVEL");

        reader->checkHash();
    }
    delete reader;
    return var;
}

void Snapshot::checkState() // logical check
{
    int countBox = state["BOX-COUNT"][0];
    int countMapY = state["HEIGHT"][0];

    int trueCount = 12 + countBox + countMapY;
    if(int(state.size()) != trueCount)
        throw SnapshotException(SnapshotException::Reason::INCORRECT_COUNT,
                                std::to_string(trueCount) + " vs " + std::to_string(state.size()));
}





