#include "LevelReader.h"

LevelReader::LevelReader(int level)
{
    QString nameFile = "/home/aleksey/Projects/OOP/Lab1/Lab1/Levels/lvl" + QString::number(level) + ".txt";
    levelFile = new QFile(nameFile);
    readFile();
}

const std::vector<std::vector<CellSpace::TypeOfCell>> &LevelReader::getType_map() const
{
    return type_map;
}

void LevelReader::sendCignal()
{
    game->notify(this, "lvlReader");
}

void LevelReader::readFile()
{
    if(levelFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        in = new QTextStream(levelFile);

        QString line;

        width = in->readLine().toInt();
        height = in->readLine().toInt();
        numBox = in->readLine().toInt();
        boxXY = std::vector<QPoint*>(numBox);
        type_map = std::vector<std::vector<CellSpace::TypeOfCell>>(height, std::vector<CellSpace::TypeOfCell>(width, CellSpace::EMPTY));

        for(int indexY = 0; indexY < height; indexY++)
        {
            line = in->readLine();
            for(int indexX = 0; indexX < width; indexX++)
                type_map[indexY][indexX] = getType(line.at(indexX));
        }

        QList<QString> listXY;
        for(int indexY = 0; indexY < numBox; indexY++)
        {
            line = in->readLine();
            listXY = line.split(",");
            boxXY[indexY] = new QPoint();
            boxXY[indexY]->setX(listXY.at(0).toInt());
            boxXY[indexY]->setY(listXY.at(1).toInt());
        }

        conditionHiddenDoors = in->readLine().toInt();
        line = in->readLine();
        listXY = line.split(",");
        hidDoorXY.setX(listXY.at(0).toInt());
        hidDoorXY.setY(listXY.at(1).toInt());

        conditionVictory = in->readLine().toInt();

        levelFile->close();
        delete levelFile;
        levelFile = nullptr;
    }
}

CellSpace::TypeOfCell LevelReader::getType(QChar ch)
{
    switch (ch.unicode()) {
    case 'w':
        return CellSpace::WALL;
    case 'g':
        return CellSpace::GRASS;
    case 't':
        return CellSpace::TARGET_BOX;
    case '-':
        return CellSpace::END_CELL;
    default:
        break;
    }
}

int LevelReader::getConditionVictory() const
{
    return conditionVictory;
}

int LevelReader::getConditionHiddenDoors() const
{
    return conditionHiddenDoors;
}

QPoint LevelReader::getHidDoorXY() const
{
    return hidDoorXY;
}

const std::vector<QPoint *> &LevelReader::getBoxXY() const
{
    return boxXY;
}

int LevelReader::getNumBox() const
{
    return numBox;
}

int LevelReader::getWidth() const
{
    return width;
}

int LevelReader::getHeight() const
{
    return height;
}
