#include "StructMapReader.h"

StructMapReader::StructMapReader(int level)
{
    filename = "lvl" + std::to_string(level) + ".txt";
}

int StructMapReader::read()
{
    file.open(filename);
    if(file.is_open())
    {
        std::string line;
        getline(file, line);
        w = std::stoi(line);

        getline(file, line);
        h = std::stoi(line);

        type_map = std::vector<std::vector<CellSpace::TypeOfCell>>(h,
                   std::vector<CellSpace::TypeOfCell>(w, CellSpace::EMPTY));
        for(int indexY = 0; indexY < h; indexY++)
        {
            getline(file, line);
            for(int indexX = 0; indexX < w; indexX++)
                type_map[indexY][indexX] = getType(line.at(indexX));
        }
    }
    else
        return -1;
    return 0;

}

CellSpace::TypeOfCell StructMapReader::getType(char ch)
{
    CellSpace::TypeOfCell type;
    switch (ch) {
    case 'w':
        type = CellSpace::WALL;
        break;
    case 'g':
        type = CellSpace::GRASS;
        break;
    }
    return type;
}

int StructMapReader::getH() const
{
    return h;
}

const std::string &StructMapReader::getFilename() const
{
    return filename;
}

int StructMapReader::getW() const
{
    return w;
}

const std::vector<std::vector<CellSpace::TypeOfCell> > &StructMapReader::getType_map() const
{
    return type_map;
}
