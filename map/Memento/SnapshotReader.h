#ifndef SNAPSHOTREADER_H
#define SNAPSHOTREADER_H

#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "SnapshotException.h"

class SnapshotReader
{
public:
    SnapshotReader(std::string index);
    std::map<std::string, std::vector<int> > getState() const;
    bool read();
private:
    std::ifstream in;
    std::string nameFile;
    std::map<std::string, std::vector<int>> state;
    bool isEnd = false;

    void tokenize(const std::string &str, std::vector<std::string> &out, std::string token);
};

#endif // SNAPSHOTREADER_H
