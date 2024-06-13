#pragma once
#include <future>
#include <SFML/Graphics/Texture.hpp>
#include "EnemyFactory.h"
#include "HeroFactory.h"
#include "BulletFactory.h"
using LoadComplete_Callback=std::function<void()>;
class MainLogic_Base
{
public:
    virtual void handleLogic()=0;

    virtual void render()=0;
    virtual ~MainLogic_Base();

    virtual void SetLoadCompleteCallback(const LoadComplete_Callback& load_complete_callback)=0;
};

class MainLogic_gameRunning : public MainLogic_Base
{
public:
    MainLogic_gameRunning();
private:
    //load enemy factory
    std::future<std::shared_ptr<EnemyFactory>> load_factory_enemy_;
    std::shared_ptr<EnemyFactory> factory_enemy_;

    //load player factory
    std::future<std::shared_ptr<HeroFactory>> load_factory_player_;
    std::shared_ptr<HeroFactory> hero_factory_;

    
    LoadComplete_Callback load_complete_callback_;

    bool isLoadComplete;
public:
    void SetLoadCompleteCallback(const LoadComplete_Callback& load_complete_callback) override;
    void handleLogic() override;
    void render() override;
};



class MainLogic_NULL : public MainLogic_Base
{
public:
    void handleLogic() override;
    void SetLoadCompleteCallback(const LoadComplete_Callback& load_complete_callback) override;
    void render() override;
};