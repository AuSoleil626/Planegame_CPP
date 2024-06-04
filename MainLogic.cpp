#include "MainLogic.h"

#include <iostream>

MainLogic_Base::~MainLogic_Base()
= default;

MainLogic_gameRunning::MainLogic_gameRunning()
{
    textureFuture=std::async(std::launch::async,[]()
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        sf::Texture texture;
        if (!texture.loadFromFile("image.png")) {
            //failed to load file
        }
        return texture;
    });
}

void MainLogic_gameRunning::handleLogic()
{
    //PlaneGame Logic
    if(textureFuture.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        std::cout<<"texture load successfully"<<"\n";
    }
}



void MainLogic_NULL::handleLogic()
{
    //Empty object
}
