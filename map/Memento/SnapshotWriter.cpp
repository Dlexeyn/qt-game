#include "SnapshotWriter.h"
#include <iostream>
#include <string>
#include <algorithm>

bool SnapshotWriter::write(std::map<std::string, std::vector<int>> &state, std::string time, std::string num)
{
    out.open(fileName);
    if(out.is_open())
    {
        char c = ':';
        time.erase(std::remove(time.begin(), time.end(), c), time.end());
        out << "TIME=" << time << '\n';
        out << "LEVEL=" << num << '\n';
        for(auto &el : state)
            writeLine(el);
        out << "END\n";
    }
    else
        return false;
    out.close();
    return true;
}

void SnapshotWriter::writeLine(std::pair<std::string, std::vector<int> > param)
{
    out << param.first << "=";
    for(size_t i = 0; i < param.second.size(); i++)
    {
        out << param.second[i];
        if(i != param.second.size() - 1)
            out << ".";
    }
    out << "\n";
}
