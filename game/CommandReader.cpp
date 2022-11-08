#include "CommandReader.h"

void CommandReader::readCommands()
{
    int count = 0;
    fin.open("Commands.txt");
    if(!fin.is_open())
    {
        sendError(NUM_KEYS-count);  // Возврат, если файла не существует
        return;
    }
    else
    {
        std::string buff = "";
        std::vector<std::string> strs;
        while(buff != "end" or fin.eof())
        {
            std::getline(fin, buff);
            if(tokenize(buff, strs))
            {
                Commands command = ch.commandFromString(ch.tolower(strs[0]));   // Считываем правую часть(до =)
                int key = keyFromString(strs[1]);                               // Считываем левую часть(после =)
                if(insertToData(std::make_pair(key, command)))
                    count++;
            }
        }
    }
    sendError(NUM_KEYS-count);  // 0 - все команды описаны, >0 - не все
    fin.close();
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

bool CommandReader::insertToData(std::pair<int, Commands> pair)
{
    if (data.find(pair.first) != data.end() or
            pair.first == Qt::Key_unknown or
            pair.second == Commands::NONE)
        return false;
    data.insert(pair);
    return true;
}

