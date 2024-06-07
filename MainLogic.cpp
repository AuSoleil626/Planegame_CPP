#include "MainLogic.h"

#include <iostream>

MainLogic_Base::~MainLogic_Base()
= default;

MainLogic_gameRunning::MainLogic_gameRunning(): bullet_factory_player_(nullptr), isLoadComplete(false)
{
    load_bullet_factory_player_=std::async(std::launch::async,[]()
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::shared_ptr<BulletFactory_Player> bullet_factory_player=std::make_shared<BulletFactory_Player>();
        return bullet_factory_player;
    });
}

void MainLogic_gameRunning::handleLogic()
{
    //PlaneGame Logic
    if(!isLoadComplete  && load_bullet_factory_player_.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        isLoadComplete=true;
        bullet_factory_player_=load_bullet_factory_player_.get();
        std::cout<<"bullet_factory_player_ load successfully "<<bullet_factory_player_.use_count()<<"\n";
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
