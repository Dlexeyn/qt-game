#include "LogData.h"

Log::Message *LogData::writeMes(Log::Message *data)
{
    auto time = std::time(nullptr);
    auto localTime = *std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(&localTime, " %H:%M:%S ");
    std::string newMesageStr = oss.str();
    newMesageStr += data->getMessage();
    data->setMessage(newMesageStr);
    return data;
}
