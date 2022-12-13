#ifndef SNAPSHOTWRITER_H
#define SNAPSHOTWRITER_H

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include "SnapshotException.h"

class SnapshotWriter
{
public:
    SnapshotWriter(std::string index)
    {
        fileName = "save_" + index + ".txt";

    }
    bool write(std::map<std::string, std::vector<int> > &state, std::string time, std::string num);
private:
    std::ofstream out;
    std::string fileName;
    void writeLine(std::pair<std::string, std::vector<int>> param);
};

#endif // SNAPSHOTWRITER_H
