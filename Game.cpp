#include "Game.h"

Game::Game():frameTime(1000/refreshRate),game_state_(GameState())
{
    game_state_= gameBegin;
}

Game::~Game()
{
}

void Game::GameStart()
{
    while (true)
    {
        auto startTime = std::chrono::steady_clock::now();

        //render thread
        
        //logic thread
        
        auto endTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
        if (elapsedTime < frameTime)
        {
            std::this_thread::sleep_for(frameTime - elapsedTime);
        }
    }
    return;
}

void Game::SetCurrentUI(std::shared_ptr<UIBase> ui)
{
    currentUI=ui;
}
