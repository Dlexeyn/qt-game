#include "SnapshotReader.h"

SnapshotReader::SnapshotReader(std::string index)
{
    nameFile = "save_" + index + ".txt";

}

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
        while(in)
        {
            source = line;
            value.clear();
            tokenize(line, temp, "=");
            if(temp.size() == 2)
            {
                key = temp[0];
                line = temp[1];
            }
            else
                throw SnapshotException(SnapshotException::Reason::INCORRECT_LINE, source);

            tokenize(line, temp, ".");
            if(temp.size() == 1)
                value.push_back(std::stoi(line));
            else if(temp.size() > 1)
            {
                for(const auto &p : temp)
                    value.push_back(std::stoi(p));
            }
            else
                throw SnapshotException(SnapshotException::Reason::INCORRECT_LINE, source);
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

void SnapshotReader::tokenize(const std::string &str, std::vector<std::string> &out, std::string token)
{
    out.clear();
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(token, end)) != std::string::npos)
    {
        end = str.find(token, start);
        out.push_back(str.substr(start, end - start));
    }

}
