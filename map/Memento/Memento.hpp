#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include <map>
#include <string>
#include <vector>
const int SIZE = 5;
class Memento {
 public:
    virtual std::string GetName() const = 0;
    virtual std::string GetTime() const = 0;
    virtual std::string num() const = 0;
    virtual void setInfo(std::string num, std::string name) = 0;
    virtual void setNum(std::string num) = 0;
    virtual std::map<std::string, std::vector<int>> GetState() const = 0;
    virtual bool saveToFile(int index) = 0;
    virtual bool readFromFile(int index) = 0;
};
#endif // MEMENTO_HPP
