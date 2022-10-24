#include "Game.h"

Game::Game(BaseWindow *baseWindow, Controller *controller, ReadData *readData)
    : baseWindow(baseWindow), controller(controller), readData(readData) {

    globalEventFactory = new GlobalEventFactory(GlobalEventFactory::Victory, baseWindow);
    victoryEvent = globalEventFactory->createEvent();

    globalEventFactory->setCurrentType(GlobalEventFactory::Lose);
    loseEvent = globalEventFactory->createEvent();
}

Game::~Game()
{
    delete globalEventFactory;
    delete victoryEvent;
    delete loseEvent;
}

void Game::notify(std::string mes)
{
    if(mes == "controller")
    {
        QPoint *posPlayer = fieldView->getXY();
        View *box = isBox(posPlayer->x() + controller->getStepX(), posPlayer->y() + controller->getStepY());
        if(boxMove(box, controller->getStepX(), controller->getStepY()))
        {
            fieldView->moving(controller->getStepX(), controller->getStepY());
            playerView->moving(controller->getStepX(), controller->getStepY());
        }
        if(playerView->getObject()->getSecondAttribute() == readData->getConditionVictory())
            victoryEvent->trigger();
        if(playerView->getObject()->getFirstAttribute() == 0)
            loseEvent->trigger();
    }
}

void Game::initGame(MapView *fieldView, View *playerView, std::vector<View*> &listBoxView, int numBox)
{
    this->fieldView = fieldView;
    this->playerView = playerView;
    this->listBoxView = listBoxView;
    this->numBox = numBox;
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
