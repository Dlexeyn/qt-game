#include "Game.h"
#include "map/Box.h"
#include "map/Field.h"
#include "objects/Player.h"
#include "graphics/FieldView.h"
#include "graphics/PlayerView.h"
#include "graphics/BoxView.h"

Game::Game(ReadData *readData, const std::vector<EventSubscriber *> &loggers, const int level)
    : readData(readData)
{
    subscribe(loggers);
    notifySubscribers("Level ", "global", new LogArgs(ArgsLog::LEVEL, level));
    field = new Field(readData, loggers);                                           // реализация поля
    fieldView = new FieldView(field, loggers, readData);                            // абстракция поля

    player = new Player(loggers);                                                   // реализация игрока
    playerView = new PlayerView(player, loggers, readData);                         // абстракция игрока

    listBox = std::vector<MapComponent*>(readData->getNumBox(), nullptr);           // реализация ящиков
    listBoxView = std::vector<View*>(readData->getNumBox(), nullptr);               // абстракция ящиков
    for(int index = 0; index < readData->getNumBox(); index++)
    {
        listBox[index] = new Box(false, loggers);
        listBoxView[index] = new BoxView(listBox[index], readData, loggers, index);
    }

    objectMediator = new GameMediator(field, player, listBox, readData);
    field->setEventMediator(objectMediator);
    player->setEventMediator(objectMediator);
    for(int index = 0; index < readData->getNumBox(); index++)
        listBox[index]->setEventMediator(objectMediator);
}

Game::~Game()
{
    notifySubscribers("Level completed", "global");
    notifySubscribers("Deleting objects", "object");
    delete globalEventFactory;
    delete victoryEvent;
    delete loseEvent;
}

void Game::notify(GLMessage *mes)
{
    switch(mes->getSender())
    {
    case Sender::CONTROLLER_PLAYER:
        movement(mes->getArg(ArgsTypes::X),
                mes->getArg(ArgsTypes::Y),
                fieldView->getXY()->rx(),
                 fieldView->getXY()->ry());
        break;
    case Sender::CONTROLLER_GAME:
        baseWindow->getMessage(mes);
        break;
    case Sender::WINDOW:
        controller->getMessage(mes);
        break;
    default:
        break;
    }
}

void Game::initGame(BaseWindow *window, Controller *controller, QGraphicsScene *scene)
{
    baseWindow = window;
    this->controller = controller;
    addObjectsOnScene(scene);

    globalEventFactory = new GlobalEventFactory(GlobalEventFactory::Victory, baseWindow);
    victoryEvent = globalEventFactory->createEvent();

    globalEventFactory->setCurrentType(GlobalEventFactory::Lose);
    loseEvent = globalEventFactory->createEvent();

    notifySubscribers("The game has started", "game");
}

void Game::setReadData(ReadData *newReadData)
{
    readData = newReadData;
}

View *Game::isBox(int x, int y)
{
    for(auto curBox : listBoxView)
    {
        if(curBox->getXY()->x() == x and
                curBox->getXY()->y() == y)
            return curBox;
    }
    return nullptr;
}

void Game::movement(int stepX, int stepY, int &x, int &y)
{
    View *box = isBox(x + stepX, y + stepY);
    if(boxMove(box, stepX, stepY))
    {
        if(fieldView->isMoving(x + stepX, y + stepY)) // Проверка на проходимость
        {
            playerView->moving(stepX, stepY);
            fieldView->moving(stepX, stepY);
            fieldView->impactOnObject(ObjectType::PLAYER, x, y);
        }
    }
    if(playerView->getObject()->getAttribute(ObjectAttribute::POINTS) == readData->getConditionVictory())
        victoryEvent->trigger();
    if(playerView->getObject()->getAttribute(ObjectAttribute::HEALTH) == 0)
        loseEvent->trigger();
}


bool Game::boxMove(View *box, int stepX, int stepY)
{
    if(!box)                                    // Коробки на пути нет
        return true;
    else{
        int &x = box->getXY()->rx();
        int &y = box->getXY()->ry();
        if(isBox(x + stepX, y + stepY))         // две коробки на пути
        {
            notifySubscribers("box : other box is on the way", "warning");
            return false;
        }
        else
        {
            if(!fieldView->isMoving(x + stepX, y + stepY))  // проверка на проходимость за коробкой
                return false;
            else
            {
                fieldView->changeView(x, y);                // Событие в клетке с коробкой - старая позиция
                box->moving(stepX, stepY);                  // движение коробки
                fieldView->changeView(x, y);                // Событие в клетке с коробкой - новая позиция
                fieldView->impactOnObject(ObjectType::BOX, x, y);
                return true;
            }
        }
    }
}

View * Game::getPlayerView() const
{
    return playerView;
}

void Game::createEvents()
{
    globalEventFactory = new GlobalEventFactory(GlobalEventFactory::Victory, baseWindow);
    victoryEvent = globalEventFactory->createEvent();

    globalEventFactory->setCurrentType(GlobalEventFactory::Lose);
    loseEvent = globalEventFactory->createEvent();
}

void Game::addObjectsOnScene(QGraphicsScene *scene)
{
    fieldView->setGameScene(scene, readData);
    playerView->setGameScene(scene, readData);
    for(auto curBox : listBoxView)
        curBox->setGameScene(scene, readData);
}


