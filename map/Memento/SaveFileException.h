#ifndef SAVEFILEEXCEPTION_H
#define SAVEFILEEXCEPTION_H

#include <exception>
#include <string>

class SaveFileException: public std::exception
{
public:
    enum class Reason{
        FILE_WAS_CHANGED, FILE_IS_CORRUPTED
    };
    explicit SaveFileException(Reason reason, std::string str);
    const char *what() const noexcept override;
private:
    std::string whatStr;
};

#endif // SAVEFILEEXCEPTION_H
