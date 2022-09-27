#include "Game.h"

Game::Game()
{
    window = new BaseWindow();
    window->show();
    controller = new Controller(window->getFieldScene());
}

void Game::gameExecute()
{
    window->setController(controller);
}
