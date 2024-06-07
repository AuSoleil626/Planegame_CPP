#pragma once
#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
class bullet_base
{
private:
    std::vector<sf::Texture> textures;
    sf::Sprite sprite_;
    double moveSpeed;
public:
    void Settextures(const std::vector<sf::Texture>& textures);
    void Setsprite(int index);
public:
    bullet_base();
    virtual ~bullet_base()=0;
};
class bullet_hero : public bullet_base
{
public:
    bullet_hero();
};
