#include "RunningUI.h"

#include <iostream>

RunningUI::RunningUI()
= default;

RunningUI::RunningUI(std::shared_ptr<sf::RenderWindow> Base_window):BaseWindow(std::move(Base_window)),
                                                                    pause_ui_(std::dynamic_pointer_cast<UIBase>(
                                                                        std::make_shared<UI_Empty>())),
                                                                    WindowSize(BaseWindow->getSize()),isPause(false)
{
    if (!bg_texture.loadFromFile(R"(.\Picture\BG.png)")) {
        std::cerr<<"Load BG failed"<<'\n';
    }
    back_ground.setTexture(bg_texture);
    if (!font.loadFromFile(R"(.\text\Conther-2.ttf)")) {
        // failed to load font
    }
    text.setFont(font);
    text.setString("Run Game......");
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(310.f, 150.f);
}

RunningUI::~RunningUI()
= default;

void RunningUI::render()
{
    BaseWindow->draw(back_ground);
    BaseWindow->draw(text);
    pause_ui_->render();
}

void RunningUI::update()
{
    eventHandle();
}

void RunningUI::eventHandle()
{
    sf::Event event;
    while (BaseWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            BaseWindow->close();            
        }
        if(event.type==sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            //generate the Pause UI
            std::cout<<"press Esc"<<"\n";
            if(!isPause)
            {
                pause_ui_=std::dynamic_pointer_cast<UIBase>(std::make_shared<PauseUI>(BaseWindow));
                isPause=true;
            }
            else
            {
                pause_ui_=std::dynamic_pointer_cast<UIBase>(std::make_shared<UI_Empty>());
                isPause=false;
            }

        }
    }
}

void RunningUI::setUI_Callback(const UI_CallBack& callback)
{
}
