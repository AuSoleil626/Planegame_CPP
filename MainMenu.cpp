#include "MainMenu.h"

#include <iostream>

MainMenu::MainMenu()
= default;

MainMenu::MainMenu(std::shared_ptr<sf::RenderWindow> Base_window):BaseWindow(std::move(Base_window))
{
    if (!bg_texture.loadFromFile(R"(C:\Users\ljw\Desktop\PlaneGame_cpp\Planegame_CPP\Picture\BG.png)")) {
        std::cout<<"Load BG failed"<<'\n';
    }
    back_ground.setTexture(bg_texture);
}


MainMenu::~MainMenu()
{
}

void MainMenu::render()
{
    BaseWindow->draw(back_ground);
}

void MainMenu::update()
{
}

void MainMenu::eventHandle()
{
}
