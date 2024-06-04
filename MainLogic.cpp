#include "MainLogic.h"

#include <iostream>

MainLogic_Base::~MainLogic_Base()
= default;

MainLogic_gameRunning::MainLogic_gameRunning():isLoadComplete(false)
{
    textureFuture=std::async(std::launch::async,[]()
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        sf::Texture texture;
        if (!texture.loadFromFile("image.png")) {
            //failed to load file
            std::cerr<<"load file error"<<"\n";
        }
        return texture;
    });
}

void MainLogic_gameRunning::handleLogic()
{
    //PlaneGame Logic
    if(!isLoadComplete  && textureFuture.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        std::cout<<"texture load successfully"<<"\n";
        isLoadComplete=true;
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
