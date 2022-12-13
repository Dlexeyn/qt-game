#include "Utilities.h"
#include <algorithm>
#include <sstream>

long long Utilities::hash(std::string &source)
{
    int x = 101, p = 15485863;
    long long h = 0;
    long long xpow = 1;

    for(int i = 0; i < int(source.size()); i ++) {
        h += source[i] * xpow % p;
        xpow *= x;
        xpow %= p;
        h %= p;
    }

    return h;
}

void Utilities::tokenize(const std::string &str, std::vector<std::string> &out, std::string token)
{
    out.clear();
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(token, end)) != std::string::npos)
    {
        end = str.find(token, start);
        out.push_back(str.substr(start, end - start));
    }
}

bool Utilities::isNumeric(const std::string &str)
{
    auto it = std::find_if(str.begin(), str.end(), [](char const &c) {
        return !std::isdigit(c);
    });

    return !str.empty() && it == str.end();
}

std::string Utilities::createMapStr(std::map<std::string, std::vector<int> > &state)
{
    std::stringstream sstr;
    int Y = state["HEIGHT"][0], X = state["WIDTH"][0];
    sstr << "Map=" << std::to_string(Y) << "x" << std::to_string(X) << '\n';

    for(int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++) {
            sstr << state["MAP_" + std::to_string(y)][x];
        }
        sstr << "\n";
    }

    int numBox = state["BOX-COUNT"][0];
    for(int i = 0; i < numBox; i++)
    {
        sstr << state["BOX_" + std::to_string(i)][0];
        sstr << state["BOX_" + std::to_string(i)][1];
    }

    sstr << "HidDoor=" << state["HIDDOR-XY"][0] << "," << state["HIDDOR-XY"][1] << '\n';

    sstr << "Player=" << state["PLAYER-XY"][0] << "," << state["PLAYER-XY"][1] << '\n';
    sstr << state["PLAYER-MAX-H"][0] << state["PLAYER-CUR-H"][0] << state["PLAYER-POINTS"][0];
    sstr << state["PLAYER-XY"][0] << state["PLAYER-XY"][1];
    return sstr.str();
}
