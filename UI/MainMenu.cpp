#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu()
= default;

MainMenu::MainMenu(std::shared_ptr<sf::RenderWindow> Base_window):BaseWindow(std::move(Base_window)),WindowSize(BaseWindow->getSize())
{
    std::cout<<BaseWindow.use_count()<<"\n";
    if (!bg_texture.loadFromFile(R"(.\Picture\BG.png)")) {
        std::cerr<<"Load BG failed"<<'\n';
    }
    back_ground.setTexture(bg_texture);
    
    
    if (!TX_Start.loadFromFile(R"(.\Picture\SG.png)")) {
        std::cerr<<"Load BG failed"<<'\n';
    }
    SP_Start.setTexture(TX_Start);
    setSpriteOrigin(SP_Start);
    SP_Start.setPosition(WindowSize.x/2,WindowSize.y/2-60);
    
    if (!TX_Exit.loadFromFile(R"(.\Picture\EG.png)")) {
        std::cerr<<"Load BG failed"<<'\n';
    }
    SP_Exit.setTexture(TX_Exit);
    setSpriteOrigin(SP_Exit);
    SP_Exit.setPosition(WindowSize.x/2,WindowSize.y/2+60);
}


MainMenu::~MainMenu()
{
}

void MainMenu::render()
{
    BaseWindow->draw(back_ground);
    BaseWindow->draw(SP_Start);
    BaseWindow->draw(SP_Exit);
}

void MainMenu::update()
{
    eventHandle();
}

void MainMenu::eventHandle()
{
    //check mouse collide
    const sf::Vector2i mousePosition = sf::Mouse::getPosition(*BaseWindow);
    if (SP_Start.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
        SP_Start.setScale(1.1f, 1.1f);
    } else {
        SP_Start.setScale(1.0f, 1.0f);
    }
    if (SP_Exit.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
        SP_Exit.setScale(1.1f, 1.1f);
    } else {
        SP_Exit.setScale(1.0f, 1.0f);
    }
    //check mouse click
    sf::Event event;
    while (BaseWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            BaseWindow->close();            
        }
        if(event.type == sf::Event::MouseButtonPressed)
        {
            if(event.mouseButton.button==sf::Mouse::Left)
            {
                if(SP_Start.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
                {
                    if(ui_call_back_)
                    {
                        ui_call_back_();
                    }
                }
                else if(SP_Exit.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
                {
                    BaseWindow->close();
                }
            }
        }
        if(event.type==sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            BaseWindow->close();
        }
    }
}

void MainMenu::setUI_Callback(const UI_CallBack& callback)
{
    ui_call_back_=callback;
}
