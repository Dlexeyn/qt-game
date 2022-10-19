#ifndef LEVELREADER_H
#define LEVELREADER_H

#include <QFile>
#include <QPoint>
#include <QList>
#include <vector>
#include <QTextStream>
#include <map/Cell.h>
#include "game/GlobalComponent.h"
#include "map/ReadData.h"

class LevelReader: public GlobalComponent
{
public:
    LevelReader(int level);
    std::vector<std::vector<CellSpace::TypeOfCell> > &getType_map();

    void sendCignal();

    void readFile();

    ReadData *getReadData() const;

private:
    ReadData *readData = nullptr;
    QFile *levelFile = nullptr;
    QTextStream *in = nullptr;

    CellSpace::TypeOfCell getType(QChar ch);
};

#endif // LEVELREADER_H
