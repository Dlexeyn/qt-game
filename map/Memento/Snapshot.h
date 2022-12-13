#ifndef SNAPSHOT_H
#define SNAPSHOT_H

#include "map/Cell.h"
#include <iostream>
#include <fstream>
#include "Memento.hpp"
#include "map/objects/Box.h"
#include "map/objects/Player.h"
#include "SnapshotWriter.h"
#include "SnapshotReader.h"
#include "log/LogObject.h"

class Snapshot: public Memento, public LogObject
{
public:
    Snapshot(const std::vector< Log::EventSubscriber* >& loggers);

    Snapshot(const std::vector<std::vector<CellSpace::Cell*>> &map_field,
             const int &map_height,
             const int &map_width,
             const QPoint *hidDoor,
             const Player &player,
             const std::vector<Box*> &BoxList,
             const int &condition,
             const int &victory);

    ~Snapshot();

    std::string num() const override { return num_; }

    std::string GetName() const override { return name; }

    std::string GetTime() const override { return time_; }

    std::map<std::string, std::vector<int>> GetState() const override;

    void setNum(std::string num) override { num_ = num; }

    void setInfo(std::string num, std::string name) override;

    bool saveToFile(int index) override;

    bool readFromFile(int index) override;

private:
    std::map<std::string, std::vector<int>> state;
    std::string num_;
    std::string name;
    std::string time_;
    SnapshotWriter *writer = nullptr;
    SnapshotReader *reader = nullptr;
    void clearOldSaves();
};

#endif // SNAPSHOT_H
