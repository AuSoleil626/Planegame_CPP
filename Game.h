#pragma once
#include <memory>
#include <iostream>
#include <chrono>
#include <thread>
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
    
public:
    void GameStart();
    void SetCurrentUI(std::shared_ptr<UIBase> ui);
};
