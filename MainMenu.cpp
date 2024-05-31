#include "MainMenu.h"

MainMenu::MainMenu()
{
}

MainMenu::MainMenu(std::shared_ptr<sf::RenderWindow> Base_window):BaseWindow(std::move(Base_window)),circle(sf::CircleShape())
{
    circle.setRadius(50); 
    circle.setPosition(400, 300);
    circle.setFillColor(sf::Color::Red); 
    circle.setOutlineColor(sf::Color::Black); 
    circle.setOutlineThickness(2);
}


MainMenu::~MainMenu()
{
}

void MainMenu::render()
{
    BaseWindow->draw(circle);
}

void MainMenu::update()
{
}

void MainMenu::eventHandle()
{
}
