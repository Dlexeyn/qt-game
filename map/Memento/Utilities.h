#ifndef UTILITIES_H
#define UTILITIES_H

#include <map>
#include <string>
#include <vector>
class Utilities
{
public:
    Utilities();
    static long long hash(std::string &source);
    static void tokenize(const std::string &str,
                         std::vector<std::string> &out,
                         std::string token);

    static bool isNumeric(std::string const &str);
    static std::string createMapStr(std::map<std::string, std::vector<int> > &state);
};

#endif // UTILITIES_H
