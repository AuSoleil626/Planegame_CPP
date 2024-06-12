#pragma once
#include <memory>

#include "BulletFactory.h"
class HeroFactory
{
public:
    HeroFactory();
    ~HeroFactory()=default;
private:
    std::shared_ptr<BulletFactory_Player> bullet_factory_player_;
    
};
