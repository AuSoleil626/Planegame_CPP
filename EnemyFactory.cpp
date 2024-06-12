#include "EnemyFactory.h"

EnemyFactory::EnemyFactory():bullet_factory_enemy_(std::make_shared<BulletFactory_Enemy>())
{
    
}
