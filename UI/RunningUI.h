#pragma once
#include "PauseUI.h"
#include "UIBase.h"

class RunningUI : public UIBase
{
private:
    std::shared_ptr<sf::RenderWindow> BaseWindow;
    std::shared_ptr<UIBase> pause_ui_;
    sf::Vector2u WindowSize;
    //bg
    sf::Sprite back_ground;
    sf::Texture bg_texture;

    sf::Font font;
    sf::Text text;

    bool isPause;
public:
    RunningUI();
    RunningUI(std::shared_ptr<sf::RenderWindow> Base_window);
    ~RunningUI() override;

public:
    void render() override;
    void update() override;
    void eventHandle() override;
    void setUI_Callback(const UI_CallBack& callback) override;
};
