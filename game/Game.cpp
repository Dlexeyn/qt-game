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
    field = new Field(readData, loggers);            // реализация поля
    fieldView = new FieldView(field, loggers, readData);     // абстракция поля

    player = new Player(loggers);                    // реализация игрока
    playerView = new PlayerView(player, loggers, readData);  // абстракция игрока

    listBox = std::vector<MapComponent*>(readData->getNumBox(), nullptr);         // реализация ящиков
    listBoxView = std::vector<View*>(readData->getNumBox(), nullptr);            // абстракция ящиков
    for(int index = 0; index < readData->getNumBox(); index++)                  //
    {                                                                          //
        listBox[index] = new Box(false, loggers);                                      //
        listBoxView[index] = new BoxView(listBox[index], readData, loggers, index);   //
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

void Game::notify(GlobalComponent* sender, GLMessage *mes)
{
    switch(mes->getSender())
    {
        case Sender::CONTROLLER:
            movement(mes->getArg(ArgsTypes::X),
                     mes->getArg(ArgsTypes::Y),
                     fieldView->getXY());
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

void Game::movement(int x, int y, QPoint* posPlayer)
{
    View *box = isBox(posPlayer->x() + x, posPlayer->y() + y);
    if(boxMove(box, x, y))
    {
        fieldView->moving(x, y);
        playerView->moving(x, y);
    }
    if(playerView->getObject()->getSecondAttribute() == readData->getConditionVictory())
        victoryEvent->trigger();
    if(playerView->getObject()->getFirstAttribute() == 0)
        loseEvent->trigger();
}


bool Game::boxMove(View *box, int stepX, int stepY)
{
    if(!box)
        return true;
    else if(isBox(box->getXY()->x() + stepX, box->getXY()->y() + stepY))
    {
        notifySubscribers("box : other box is on the way", "warning");
        return false;
    }
    else
    {
        setCurPos(2 * stepX, 2 * stepY);
        if(!fieldView->getObject()->checkState())
        {
            setCurPos();
            return false;
        }
        else
        {
            setCurPos(stepX, stepY);
            fieldView->changeView(fieldView->getObject()->changeStatus(), box->getXY()->x(), box->getXY()->y());
            box->moving(stepX, stepY);

            setCurPos(2*stepX, 2*stepY);
            fieldView->changeView(fieldView->getObject()->changeStatus(), box->getXY()->x(), box->getXY()->y());
            setCurPos();
            return true;
        }
    }
}

void Game::setCurPos(int addX, int addY)
{
    fieldView->getObject()->setFirstAttribute(playerView->getXY()->x() + addX);
    fieldView->getObject()->setSecondAttribute(playerView->getXY()->y() + addY);
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


