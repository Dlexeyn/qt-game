#ifndef LEVELREADER_H
#define LEVELREADER_H

#include <QFile>
#include <QPoint>
#include <QList>
#include <vector>
#include <QTextStream>
#include <map/Cell.h>
#include "game/GlobalComponent.h"

class LevelReader: public GlobalComponent
{
public:
    LevelReader(int level);
    const std::vector<std::vector<CellSpace::TypeOfCell> > &getType_map() const;

    void sendCignal();

    void readFile();

    int getHeight() const;

    int getWidth() const;

    int getNumBox() const;

    int getConditionHiddenDoors() const;

    QPoint getHidDoorXY() const;

    const std::vector<QPoint *> &getBoxXY() const;

    int getConditionVictory() const;

private:
    std::vector<std::vector<CellSpace::TypeOfCell>> type_map;
    std::vector<QPoint*> boxXY;
    QPoint hidDoorXY;
    QFile *levelFile = nullptr;
    QTextStream *in = nullptr;

    CellSpace::TypeOfCell getType(QChar ch);
    int width, height;
    int numBox;
    int conditionHiddenDoors;
    int conditionVictory;

};

#endif // LEVELREADER_H
