#pragma once
#include "UIBase.h"
class LoadMenu : public UIBase
{
private:
    std::shared_ptr<sf::RenderWindow> BaseWindow;

    sf::Vector2u WindowSize;
    //bg
    sf::Sprite back_ground;
    sf::Texture bg_texture;

    sf::Font font;
    sf::Text text;
public:
    LoadMenu();
    LoadMenu(std::shared_ptr<sf::RenderWindow> Base_window);
    ~LoadMenu() override;

public:
    void render() override;
    void update() override;
    void eventHandle() override;
    void setUI_Callback(const UI_CallBack& callback) override;
};
