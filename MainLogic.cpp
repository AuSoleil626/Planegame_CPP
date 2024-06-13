#include "MainLogic.h"

#include <iostream>

MainLogic_Base::~MainLogic_Base()
= default;

MainLogic_gameRunning::MainLogic_gameRunning(): factory_enemy_(nullptr), hero_factory_(nullptr), isLoadComplete(false)
{
    load_factory_enemy_=std::async(std::launch::async,[]()
    {
        //std::this_thread::sleep_for(std::chrono::seconds(2));
        std::shared_ptr<EnemyFactory> factory_enemy_factory=std::make_shared<EnemyFactory>();
        return factory_enemy_factory;
    });
    load_factory_player_=std::async(std::launch::async,[]()
    {
        //std::this_thread::sleep_for(std::chrono::seconds(2));
        std::shared_ptr<HeroFactory> factory_enemy_factory=std::make_shared<HeroFactory>();
        return factory_enemy_factory;
    });
}

void MainLogic_gameRunning::handleLogic()
{
    //PlaneGame Logic
    if(!isLoadComplete
        && load_factory_enemy_.wait_for(std::chrono::seconds(0)) == std::future_status::ready
        && load_factory_player_.wait_for(std::chrono::seconds(0))== std::future_status::ready)
    {
        isLoadComplete=true;
        factory_enemy_=load_factory_enemy_.get();
        hero_factory_=load_factory_player_.get();
        //std::cout<<"bullet_factory_player_ load successfully "<<factory_enemy_.use_count()<<"\n";
        if(load_complete_callback_)
        {
            load_complete_callback_();
        }
    }
    //std::cout<<"rungame"<<"\n";
}

void MainLogic_gameRunning::render()
{
}


void MainLogic_gameRunning::SetLoadCompleteCallback(const LoadComplete_Callback& load_complete_callback)
{
    this->load_complete_callback_=load_complete_callback;
}

void MainLogic_NULL::handleLogic()
{
    //Empty object
}

void MainLogic_NULL::SetLoadCompleteCallback(const LoadComplete_Callback& load_complete_callback)
{
}

void MainLogic_NULL::render()
{
}
