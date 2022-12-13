#ifndef SNAPSHOTREADER_H
#define SNAPSHOTREADER_H

#include <string>
#include <vector>
#include <fstream>
#include <map>


class SnapshotReader
{
public:
    SnapshotReader(std::string index) { nameFile = "save_" + index + ".txt"; }
    std::map<std::string, std::vector<int> > getState() const;
    bool read();
    void checkHash();
private:
    std::ifstream in;
    std::string nameFile;
    std::string hash = "";
    std::map<std::string, std::vector<int>> state;
    bool isEnd = false;

    std::vector<std::string> true_params =
    {
        "TIME", "LEVEL", "BOX", "MAP", "BOX-COUNT",
        "HEIGHT", "WIDTH", "HIDDOR-CONDITION",
        "HIDDOR-XY", "PLAYER-CUR-H", "PLAYER-MAX-H",
        "PLAYER-POINTS", "PLAYER-XY", "VICTORY-CONDITION"
    };

    void checkKey(const std::string &str);
    void checkValue(const std::string &str);
};

#endif // SNAPSHOTREADER_H
