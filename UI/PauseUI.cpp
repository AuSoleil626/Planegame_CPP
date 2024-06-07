#include "PauseUI.h"

PauseUI::PauseUI(std::shared_ptr<sf::RenderWindow> Base_Window):BaseWindow(std::move(Base_Window)),WindowSize(BaseWindow->getSize())
{
    if (!font_.loadFromFile(R"(.\text\Conther-2.ttf)")) {
        // failed to load font
    }
    text_.setFont(font_);
    text_.setString("Game Pause");
    text_.setCharacterSize(32);
    text_.setFillColor(sf::Color::Black);
    text_.setStyle(sf::Text::Bold);
    text_.setPosition(200.f, 200);
}

void PauseUI::render()
{
    BaseWindow->draw(text_);
}

void PauseUI::update()
{
}

void PauseUI::eventHandle()
{
}

void PauseUI::setUI_Callback(const UI_CallBack& callback)
{
}
