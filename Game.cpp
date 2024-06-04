#include "Game.h"

#include <memory>
#include <set>
#include <SFML/Window/Event.hpp>

#include "LoadMenu.h"
#include "MainLogic.h"
#include "MainMenu.h"
#include "UIBase.h"

Game::Game():refreshRate(60),frameTime(1000/refreshRate),
            game_state_(GameState()),window_(std::make_shared<sf::RenderWindow>(sf::VideoMode(960, 478), "SFML Window")),
            planegame_(std::dynamic_pointer_cast<MainLogic_Base>(std::make_shared<MainLogic_NULL>()))
            
{
    game_state_= gameBegin;
}



void Game::GameStart()
{
    UpdateGameState();
    while (window_->isOpen() && game_state_!=gameEnd)
    {
        auto startTime = std::chrono::steady_clock::now();
        GameState previous_state=game_state_;

        currentUI->update();

        planegame_->handleLogic();

        GameRender();
        
        HandleEvents();
        
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
            planegame_=std::dynamic_pointer_cast<MainLogic_Base>(std::make_shared<MainLogic_NULL>());
            SetCurrentUI(std::dynamic_pointer_cast<UIBase>(std::make_shared<MainMenu>(window_)));
            currentUI->setUI_Callback([this]{this->ChangeGameState(gameLoading);});
            break;            
        }

    case gameLoading:
        {
            planegame_=std::dynamic_pointer_cast<MainLogic_Base>(std::make_shared<MainLogic_gameRunning>());
            SetCurrentUI(std::dynamic_pointer_cast<UIBase>(std::make_shared<LoadMenu>(window_)));
            std::cout<<"Gameloading"<<"\n";
            break;   
        }

    case gameRunning:
        {
            planegame_=std::dynamic_pointer_cast<MainLogic_Base>(std::make_shared<MainLogic_gameRunning>());
            break;            
        }

    case gameEnd:
        {
            planegame_=std::dynamic_pointer_cast<MainLogic_Base>(std::make_shared<MainLogic_NULL>());
            break;   
        }

    default:
        break;
    }
}

void Game::GameRender() const
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
void Game::ChangeGameState(GameState state)
{
    game_state_=state;
}

Game& Game::getGameInstance()
{
    static Game instance;
    return instance;
}
