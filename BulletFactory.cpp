#include "BulletFactory.h"

#include <iostream>

BulletFactory_Base::~BulletFactory_Base()
= default;

void BulletFactory_Base::addTexture(const sf::Texture& texture)
{
    textures_.push_back(texture);
}

BulletFactory_Enemy::BulletFactory_Enemy()
{
    std::string basePath=R"(.\Picture\敌人01\子弹01)";
    for(int i=1;i<3;i++)
    {
        sf::Texture texture;
        std::string filename = basePath + "子弹0"+ std::to_string(i) + ".png";
        if(!texture.loadFromFile(filename))
        {
            std::cerr<<"bulletfactory enemy load bullet failed"<<"\n";
        }
        addTexture(texture);
    }
}

BulletFactory_Player::BulletFactory_Player()
{
    std::string basePath=R"(.\Picture\png2\)";
    for(int i=1;i<10;i++)
    {
        sf::Texture texture;
        std::string filename = basePath + std::to_string(i) + ".png";
        if(!texture.loadFromFile(filename))
        {
            std::cerr<<"bulletfactory player load bullet failed"<<"\n";
        }
        addTexture(texture);
    }
}
