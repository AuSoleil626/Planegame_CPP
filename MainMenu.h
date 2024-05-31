#pragma once
#include "UIBase.h"
#include <SFML/Graphics.hpp>
class MainMenu : public UIBase
{
private:
    std::shared_ptr<sf::RenderWindow> BaseWindow;
    sf::CircleShape circle;
public:
    MainMenu();
    MainMenu(std::shared_ptr<sf::RenderWindow> Base_window);
    ~MainMenu() override;

public:
    void render() override;
    void update() override;
    void eventHandle() override;
};
