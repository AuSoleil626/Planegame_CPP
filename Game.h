#pragma once
#include <memory>
#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics/RenderWindow.hpp>

enum GameState
{
    gameBegin,
    gameLoading,
    gameRunning,
    gameEnd
};
class UIBase;

class Game
{
public:
    explicit Game();
    ~Game();
private:
    std::shared_ptr<UIBase> currentUI;

    //Frame rate
    int refreshRate=60;
    std::chrono::milliseconds frameTime;

    //Gamestate
    GameState game_state_;

    //Base Window
    std::shared_ptr<sf::RenderWindow> window_;


    
public:
    void GameStart();
    void SetCurrentUI(std::shared_ptr<UIBase> ui);
    void UpdateGameState();
    void GameRender();
    void HandleEvents();
};
