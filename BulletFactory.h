#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>

class BulletFactory_Base
{
public:
    BulletFactory_Base()=default;
    virtual ~BulletFactory_Base()=0;

    void addTexture(const sf::Texture& texture);
    
private:
    std::vector<sf::Texture> textures_;
};
class BulletFactory_Enemy:public BulletFactory_Base
{
public:
    BulletFactory_Enemy();
};
class BulletFactory_Player:public BulletFactory_Base
{
public:
    BulletFactory_Player();

};