#include "SnapshotException.h"


SnapshotException::SnapshotException(Reason reason, std::string info)
{
    std::map<Reason, std::string> errors =
    {
        {Reason::INCORRECT_LINE, "Incorrect line: "},
        {Reason::INCORRECT_END, "Incorrect end of file"},
        {Reason::INCORRECT_KEY, "Incorrect name of parameter: "},
        {Reason::INCORRECT_VALUE, "Incorrect value: "},
        {Reason::INCORRECT_COUNT, "Incorrect count of lines: "},
        {Reason::LOGICAL_ERROR, "Logical error in parameter: "}
    };
    whatStr = snap + errors[reason] + info;
}

const char *SnapshotException::what() const noexcept
{
    return whatStr.c_str();
}
