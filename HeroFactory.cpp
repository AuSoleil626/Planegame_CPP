#include "HeroFactory.h"

HeroFactory::HeroFactory():bullet_factory_player_(std::make_shared<BulletFactory_Player>())
{
    
}
