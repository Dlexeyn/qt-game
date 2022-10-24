#include "LevelReader.h"

LevelReader::LevelReader(int level)
{
    readData = new ReadData();
    QString nameFile = "/home/aleksey/Projects/OOP/Lab1/Lab1/Levels/lvl" + QString::number(level) + ".txt";
    levelFile = new QFile(nameFile);
    readFile();
}

void LevelReader::sendCignal()
{
    game->notify("lvlReader");
}

void LevelReader::readFile()
{
    if(levelFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        in = new QTextStream(levelFile);

        QString line;
        QList<QString> listXY;

        readData->width = in->readLine().toInt();
        readData->height = in->readLine().toInt();
        readData->startW = -(readData->sizeCell/2) * (readData->width-1);
        readData->startH = -(readData->sizeCell/2) * (readData->height-1);
        readData->numBox = in->readLine().toInt();

        line = in->readLine();
        listXY = line.split(",");

        readData->playerXY = new QPoint();
        readData->playerXY->setX(listXY.at(0).toInt());
        readData->playerXY->setY(listXY.at(1).toInt());

        readData->boxXY = std::vector<QPoint*>(readData->numBox);
        readData->type_map = std::vector<std::vector<CellSpace::TypeOfCell>>(readData->height,
                                                                             std::vector<CellSpace::TypeOfCell>(readData->width, CellSpace::EMPTY));

        for(int indexY = 0; indexY < readData->height; indexY++)
        {
            line = in->readLine();
            for(int indexX = 0; indexX < readData->width; indexX++)
                readData->type_map[indexY][indexX] = getType(line.at(indexX));
        }

        for(int indexY = 0; indexY < readData->numBox; indexY++)
        {
            line = in->readLine();
            listXY = line.split(",");
            readData->boxXY[indexY] = new QPoint();
            readData->boxXY[indexY]->setX(listXY.at(0).toInt());
            readData->boxXY[indexY]->setY(listXY.at(1).toInt());
        }

        readData->conditionHiddenDoors = in->readLine().toInt();
        line = in->readLine();
        listXY = line.split(",");
        readData->hidDoorXY = new QPoint();
        readData->hidDoorXY->setX(listXY.at(0).toInt());
        readData->hidDoorXY->setY(listXY.at(1).toInt());

        readData->conditionVictory = in->readLine().toInt();

        levelFile->close();
        delete levelFile;
        levelFile = nullptr;

        isReading = true;
    }
    else
        isReading = false;
}

ReadData *LevelReader::getReadData() const
{
    return readData;
}

CellSpace::TypeOfCell LevelReader::getType(QChar ch)
{
    CellSpace::TypeOfCell type;
    switch (ch.unicode()) {
    case 'w':
        type = CellSpace::WALL;
        break;
    case 'W':
        type = CellSpace::TEMP_WALL;
        break;
    case 'g':
        type = CellSpace::GRASS;
        break;
    case 't':
        type = CellSpace::TARGET_BOX;
        break;
    case '-':
        type = CellSpace::END_CELL;
        break;
    default:
        break;
    }
    return type;
}

bool LevelReader::getIsReading() const
{
    return isReading;
}
