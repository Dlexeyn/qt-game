#ifndef FILELOGDECORATOR_H
#define FILELOGDECORATOR_H

#include "LogDecorator.h"
#include <fstream>

class FileLogDecorator : public LogDecorator
{
public:
    FileLogDecorator(LogSource *logSource);
    ~FileLogDecorator();
    Log::Message *writeMes(Log::Message *data);

private:
    std::ofstream fout;

};

#endif // FILELOGDECORATOR_H
