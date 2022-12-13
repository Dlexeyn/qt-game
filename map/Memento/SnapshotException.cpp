#include "SnapshotException.h"


SnapshotException::SnapshotException(Reason reason, std::string info)
{
    std::map<Reason, std::string> errors =
    {
        {Reason::INCORRECT_LINE, "Incorrect line: "},
        {Reason::INCORRECT_END, "Incorrect end of file"},
        {Reason::INCORRECT_TIME, "Incorrect time line in reading file: "},
        {Reason::INCORRECT_LEVEL, "Incorrect level line in reading file: "},
        {Reason::INCORRECT_MAP_LINE, "Incorrect map line: "}
    };
    whatStr = snap + errors[reason] + info;
}

const char *SnapshotException::what() const noexcept
{
    return whatStr.c_str();
}
