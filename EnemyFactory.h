#pragma once
#include <memory>

#include "BulletFactory.h"
class EnemyFactory
{
public:
    EnemyFactory();
    ~EnemyFactory()=default;
private:
    std::shared_ptr<BulletFactory_Enemy> bullet_factory_enemy_;
    
};
