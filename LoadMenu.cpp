#include "LoadMenu.h"

#include <iostream>
#include <utility>

LoadMenu::LoadMenu()=default;

LoadMenu::LoadMenu(std::shared_ptr<sf::RenderWindow> Base_window):BaseWindow(std::move(Base_window)),WindowSize(BaseWindow->getSize())
{
    std::cout<<BaseWindow.use_count()<<"\n";
    if (!bg_texture.loadFromFile(R"(.\Picture\BG.png)")) {
        std::cerr<<"Load BG failed"<<'\n';
    }
    back_ground.setTexture(bg_texture);
    if (!font.loadFromFile(R"(.\text\Conther-2.ttf)")) {
        // failed to load font
    }
    text.setFont(font);
    text.setString("Loading......");
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(310.f, 150.f);
}

LoadMenu::~LoadMenu()
= default;

void LoadMenu::render()
{
    BaseWindow->draw(back_ground);
    BaseWindow->draw(text);
}

void LoadMenu::update()
{
    eventHandle();
}

void LoadMenu::eventHandle()
{
    sf::Event event;
    while (BaseWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            BaseWindow->close();            
        }
    }
}

void LoadMenu::setUI_Callback(const UI_CallBack& callback)
{
    
}

