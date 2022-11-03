#include "FileLogDecorator.h"

FileLogDecorator::FileLogDecorator(LogSource *logSource)
    : LogDecorator(logSource)
{
    fout.open("Logs.txt", std::ios::app);
}

FileLogDecorator::~FileLogDecorator()
{
    fout.close();
}

Log::Message *FileLogDecorator::writeMes(Log::Message *data)
{
    data = logSource->writeMes(data);
    fout << data << "\n";
    return data;
}
