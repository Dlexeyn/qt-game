#ifndef STRUCTMAPREADER_H
#define STRUCTMAPREADER_H
#include <fstream>
#include "map/Cell.h"


class StructMapReader
{
public:
    StructMapReader(int level);

    int read();

    const std::vector<std::vector<CellSpace::TypeOfCell> > &getType_map() const;

    int getW() const;

    int getH() const;

    const std::string &getFilename() const;

private:
    std::string filename;

    CellSpace::TypeOfCell getType(char ch);
    std::ifstream file;
    std::vector<std::vector                              //
                   <CellSpace::TypeOfCell>> type_map;   // cell
    int w, h;
};

#endif // STRUCTMAPREADER_H
