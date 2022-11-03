#ifndef READER_H
#define READER_H

#include "AbstractReader.h"

class Reader : public AbstractReader
{
public:
    Reader(std::map <int, Commands> *data) : data(data) {}
    void setData(std::map <int, Commands> *data);
protected:
    const int NUM_KEYS = 9;
    CommandsHelper ch;
    std::map <int, Commands> *data;
};

#endif // READER_H
