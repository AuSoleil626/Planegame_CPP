#include "UIBase.h"

UIBase::UIBase()
{
}

UIBase::~UIBase()
{
}

void UIBase::setSpriteOrigin(sf::Sprite& sprite)
{
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

void UI_Empty::render()
{
}

void UI_Empty::update()
{
}

void UI_Empty::eventHandle()
{
}

void UI_Empty::setUI_Callback(const UI_CallBack& callback)
{
}
