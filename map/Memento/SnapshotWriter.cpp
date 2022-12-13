#include "SnapshotWriter.h"
#include "Utilities.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

bool SnapshotWriter::write(std::map<std::string, std::vector<int>> &state, std::string time, std::string num)
{
    out.open(fileName);
    if(out.is_open())
    {
        std::string str = Utilities::createMapStr(state);
        out << Utilities::hash(str) << '\n';

        char c = ':';
        time.erase(std::remove(time.begin(), time.end(), c), time.end());

        for(auto s: time)
            state["TIME"].push_back(s - '0');
        state["LEVEL"].push_back(std::stoi(num));

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