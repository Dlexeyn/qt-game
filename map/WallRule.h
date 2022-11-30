#ifndef WALLRULE_H
#define WALLRULE_H
#include "Field.h"
#include "map/StructMapReader.h"

template <map::level lvl>
class WallRule
{
public:
    WallRule() {}
    std::string fill(map::Field &field)
    {
        StructMapReader reader((int(lvl)));
        if(reader.read())
            return "the file " + reader.getFilename() + " deleted or corrupted";
        int h = reader.getH(), w = reader.getW();

        field.setMap_width(w);
        field.setMap_height(h);
        field.setMap_field(std::vector<std::vector<Cell*>>
                            (h, std::vector<Cell*>(w, nullptr)));

        const std::vector< std::vector<CellSpace::TypeOfCell> > &map
                = reader.getType_map();
        for(int y = 0; y < h; y++)
            for(int x = 0; x < w; x++)
            {
                CellSpace::Cell *newCell = new CellSpace::Cell(map[y][x],
                                                              (map[y][x] == CellSpace::WALL) ? false : true);
                field.setCellInField(x, y, newCell);
            }
        return "Ok";
    }
};

#endif // WALLRULE_H
