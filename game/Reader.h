#ifndef READER_H
#define READER_H

#include "AbstractReader.h"

class Reader : public AbstractReader
{
public:
    Reader(){}
    ~Reader(){}
    const std::map<int, Commands> &getData() const;

protected:
    std::map<int, Commands> DefaultData;

    CommandsHelper ch;
    std::map <int, Commands> data;

    void sendError(int flag);
    void createDefaultData();
};

#endif // READER_H
