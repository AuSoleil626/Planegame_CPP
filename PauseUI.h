#pragma once
#include "UIBase.h"

class PauseUI:public UIBase
{
public:
    PauseUI() = default;
    PauseUI(std::shared_ptr<sf::RenderWindow> Base_Window);
    ~PauseUI() override = default;
    void render() override;
    void update() override;
    void eventHandle() override;
    void setUI_Callback(const UI_CallBack& callback) override;
private:
    std::shared_ptr<sf::RenderWindow> BaseWindow;
    sf::Vector2u WindowSize;
    sf::Text text_;
    sf::Font font_;
};
