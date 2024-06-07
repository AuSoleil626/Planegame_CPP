#include "Bullet.h"


void bullet_base::Settextures(const std::vector<sf::Texture>& textures)
{
    this->textures=textures;
}

void bullet_base::Setsprite(int index)
{
    sprite_.setTexture(textures[index]);
}

bullet_base::bullet_base():moveSpeed(3)
{
}

bullet_base::~bullet_base()
= default;
