#ifndef FILELOGDECORATOR_H
#define FILELOGDECORATOR_H

#include "LogDecorator.h"
#include <fstream>

class FileLogDecorator : public LogDecorator
{
public:
    FileLogDecorator();
    ~FileLogDecorator();
    Log::Message *sendMessage();

private:
    std::ofstream fout;

};

#endif // FILELOGDECORATOR_H
