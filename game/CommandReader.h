#ifndef COMMANDREADER_H
#define COMMANDREADER_H

#include <QKeySequence>
#include <fstream>
#include <Qt>
#include <vector>
#include "Reader.h"

class CommandReader : public Reader
{
public:
    using Reader::Reader;
    int readCommands();

private:
    std::ifstream fin;
    bool tokenize(std::string const &str, std::vector<std::string> &out);
    int keyFromString(const std::string &value);
};

#endif // COMMANDREADER_H
