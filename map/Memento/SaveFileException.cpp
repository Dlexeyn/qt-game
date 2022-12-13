#include "SaveFileException.h"


SaveFileException::SaveFileException(Reason reason, std::string str) {
    if(reason == Reason::FILE_IS_CORRUPTED)
        whatStr = "The file " + str + " is corrupted!";
    else
        whatStr = "The file " + str + " was changed!";
}

const char *SaveFileException::what() const noexcept
{
    return whatStr.c_str();
}
