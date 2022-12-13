#include "SnapshotReader.h"
#include "SnapshotException.h"
#include "Utilities.h"
#include "map/Memento/SaveFileException.h"
#include <algorithm>

std::map<std::string, std::vector<int> > SnapshotReader::getState() const
{
    return state;
}

bool SnapshotReader::read()
{
    in.open(nameFile);
    std::string line;
    std::string source;
    std::vector<std::string> temp;

    std::string key;
    std::vector<int> value;

    if(in.is_open())
    {
        in >> line;
        hash = line;
        if(!Utilities::isNumeric(hash))
            throw SaveFileException(SaveFileException::Reason::FILE_IS_CORRUPTED, nameFile);
        in >> line;
        while(in)
        {
            source = line;
            value.clear();
            Utilities::tokenize(line, temp, "=");
            if(temp.size() == 2)
            {
                key = temp[0];
                checkKey(key);
                line = temp[1];
            }
            else
                throw SnapshotException(SnapshotException::Reason::INCORRECT_LINE,
                                        source);

            Utilities::tokenize(line, temp, ".");
            if(temp.size() == 1)
            {
                checkValue(line);
                value.push_back(std::stoi(line));
            }
            else if(temp.size() > 1)
            {
                for(const auto &p : temp)
                {
                    checkValue(p);
                    value.push_back(std::stoi(p));
                }
            }
            else
                throw SnapshotException(SnapshotException::Reason::INCORRECT_LINE,
                                        source);
            state[key] = value;
            in >> line;

            if(line == "END")
            {
                isEnd = true;
                break;
            }
        }
    }
    else
        return false;
    in.close();
    return true;
}

void SnapshotReader::checkKey(const std::string &str)
{
    std::vector<std::string> out;
    Utilities::tokenize(str, out, "_");
    if(out.size() == 1)
    {
        if(str == "BOX" or str == "MAP" or
                std::find(true_params.begin(), true_params.end(), str) == true_params.end())
            throw SnapshotException(SnapshotException::Reason::INCORRECT_KEY, str);
    }
    else if(out.size() == 2)
    {
        if(std::find(true_params.begin(), true_params.end(), out[0]) == true_params.end()
                or !Utilities::isNumeric(out[1]))
            throw SnapshotException(SnapshotException::Reason::INCORRECT_KEY, str);
    } else
        throw SnapshotException(SnapshotException::Reason::INCORRECT_KEY, str);

}

void SnapshotReader::checkValue(const std::string &str)
{
    if(!Utilities::isNumeric(str))
        throw SnapshotException(SnapshotException::Reason::INCORRECT_VALUE, str);
}

void SnapshotReader::checkHash()
{
    std::string mapStr = Utilities::createMapStr(state);
    long long hashFromFile = Utilities::hash(mapStr);
    if(std::stoi(hash) != hashFromFile)
        throw SaveFileException(SaveFileException::Reason::FILE_WAS_CHANGED, nameFile);
}



