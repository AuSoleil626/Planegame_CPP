#include "Game.h"

#include <memory>
#include <set>
#include <SFML/Window/Event.hpp>

#include "MainMenu.h"
#include "UIBase.h"

Game::Game():frameTime(1000/refreshRate),game_state_(GameState()),window_(std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "SFML Window"))
{
    game_state_= gameBegin;
}

Game::~Game()
{
}

void Game::GameStart()
{
    UpdateGameState();
    while (game_state_!=gameEnd)
    {
        auto startTime = std::chrono::steady_clock::now();
        GameState previous_state=game_state_;

        //render thread
        //std::thread renderThread(&Game::GameRender,this);
        //std::cout<<"render thread work"<<'\n';
        GameRender();

        
        HandleEvents();
        //logic thread


        //renderThread.join();
        //std::cout<<"render thread work end"<<'\n';
        
        if(game_state_ != previous_state && game_state_!=gameEnd) //means that there are some changes occured in thread
        {
            UpdateGameState();
            std::cout<<"hello";
        }
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

void Game::UpdateGameState()
{
    switch (game_state_)
    {
    case gameBegin:
        {
            SetCurrentUI(std::dynamic_pointer_cast<UIBase>(std::make_shared<MainMenu>(window_)));
            break;            
        }

    case gameLoading:
        break;
    case gameRunning:
        break;
    case gameEnd:
        break;
    default:
        break;
    }
}

void Game::GameRender()
{
    window_->clear();
    currentUI->render();
    window_->display();
}

void Game::HandleEvents()
{
    sf::Event event;
    while (window_->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            game_state_=gameEnd;
            window_->close();            
        }

    }
}
