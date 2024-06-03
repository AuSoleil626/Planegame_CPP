#pragma once
#include "UIBase.h"
#include <SFML/Graphics.hpp>

class MainMenu : public UIBase
{
private:
    std::shared_ptr<sf::RenderWindow> BaseWindow;

    sf::Vector2u WindowSize;
    //bg
    sf::Sprite back_ground;
    sf::Texture bg_texture;
    //start game
    sf::Texture TX_Start;
    sf::Sprite SP_Start;
    //exit game
    sf::Texture TX_Exit;
    sf::Sprite SP_Exit;

    UI_CallBack ui_call_back_;
public:
    MainMenu();
    MainMenu(std::shared_ptr<sf::RenderWindow> Base_window);
    ~MainMenu() override;

public:
    void render() override;
    void update() override;
    void eventHandle() override;
    void setUI_Callback(const UI_CallBack& callback) override;
};
