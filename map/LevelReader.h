#ifndef LEVELREADER_H
#define LEVELREADER_H

#include <QFile>
#include <QPoint>
#include <QList>
#include <vector>
#include <QTextStream>
#include <map/Cell.h>
#include "map/ReadData.h"

class LevelReader
{
public:
    LevelReader(int level);
    std::vector<std::vector<CellSpace::TypeOfCell> > &getType_map();

    void readFile();

    ReadData *getReadData() const;

    bool getIsReading() const;

private:
    ReadData *readData = nullptr;
    QFile *levelFile = nullptr;
    QTextStream *in = nullptr;

    CellSpace::TypeOfCell getType(QChar ch);
    bool isReading = false;
};

#endif // LEVELREADER_H
