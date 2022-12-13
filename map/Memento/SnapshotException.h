#ifndef SNAPSHOTEXCEPTION_H
#define SNAPSHOTEXCEPTION_H

#include <stdexcept>
#include <map>

class SnapshotException: public std::exception
{
public:
    enum class Reason{
        INCORRECT_LINE,
        INCORRECT_TIME,
        INCORRECT_LEVEL,
        INCORRECT_END,
        INCORRECT_MAP_LINE,
    };

    explicit SnapshotException(Reason reason, std::string info = "");
    const char *what() const noexcept override;
private:
    std::string whatStr;
    const std::string snap = "Loading save: ";
};

#endif // SNAPSHOTEXCEPTION_H
