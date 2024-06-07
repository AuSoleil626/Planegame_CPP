#pragma once
#include <functional>
#include <SFML/Graphics.hpp>
using UI_CallBack=std::function<void()>;
class UIBase
{
public:
    UIBase();
    virtual ~UIBase();
public:
    virtual void render() =0; 
    virtual void update() =0;
    virtual void eventHandle()=0;
    
public:
    void setSpriteOrigin(sf::Sprite &sprite);

    virtual void setUI_Callback(const UI_CallBack& callback)=0;
};
class UI_Empty:public UIBase
{
public:
    void render() override;
    void update() override;
    void eventHandle() override;
    void setUI_Callback(const UI_CallBack& callback) override;
};