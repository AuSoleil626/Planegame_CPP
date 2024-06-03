#pragma once
#include <memory>
#include <iostream>
#include <chrono>
#include <functional>
#include <thread>
#include <SFML/Graphics/RenderWindow.hpp>
//using UI_CallBack=std::function<void()>;
enum GameState
{
    gameBegin,
    gameLoading,
    gameRunning,
    gameEnd
};
class UIBase;
class MainLogic_Base;

class Game
{

    
private:
    std::shared_ptr<UIBase> currentUI;

    //Frame rate
    int refreshRate;
    std::chrono::milliseconds frameTime;

    //Gamestate
    GameState game_state_;

    //Base Window
    std::shared_ptr<sf::RenderWindow> window_;

    std::shared_ptr<MainLogic_Base> planegame_;


private:
    explicit Game();
    Game(const Game&)=delete;
    Game& operator=(const Game&)=delete;
    
public:
    void GameStart();
    void SetCurrentUI(std::shared_ptr<UIBase> ui);
    void UpdateGameState();
    void GameRender();
    void HandleEvents();
    void ChangeGameState(GameState state);
    static Game& getGameInstance();
};
