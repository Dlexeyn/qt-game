#include "FileLogDecorator.h"

FileLogDecorator::FileLogDecorator()
{
    fout.open("Logs.txt");
}

FileLogDecorator::~FileLogDecorator()
{
    fout.close();
}

Log::Message *FileLogDecorator::sendMessage()
{
    Log::Message *mes = logSource->sendMessage();
    fout << mes << "\n";
    return mes;
}
