#include "CommandReader.h"

int CommandReader::readCommands()
{
    int count = 0;
    fin.open("Commands.txt");
    if(!fin.is_open())
        return NUM_KEYS-count;  // Возврат, если файла не существует
    else
    {
        std::string buff = "";
        std::vector<std::string> strs;
        while(buff != "end")
        {
            std::getline(fin, buff);
            if(tokenize(buff, strs))
            {
                Commands command = ch.commandFromString(ch.tolower(strs[0]));
                int key = keyFromString(strs[1]);
                data->insert(std::pair<int, Commands>(key, command));
                count++;
            }
            else
                return NUM_KEYS-count;  // Возврат, если не правильно описана строка
        }
    }
    return NUM_KEYS-count;  // 0 - все команды описаны, >0 - не все
}

bool CommandReader::tokenize(const std::string &str, std::vector<std::string> &out)
{
    out.clear();
    size_t start;
    size_t end = 0;
    int count = 0;
    std::string token = "=";

    while ((start = str.find_first_not_of(token, end)) != std::string::npos)
    {
        end = str.find(token, start);
        out.push_back(str.substr(start, end - start));
        count++;
    }

    if(count == 2)
        return true;
    return false;
}

int CommandReader::keyFromString(const std::string &value)
{
    QString str = QString::fromStdString(value);
    QKeySequence seq = QKeySequence(str);
    return seq[0];
}
