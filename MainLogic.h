#pragma once
#include <future>
#include <SFML/Graphics/Texture.hpp>

class MainLogic_Base
{
public:
    virtual void handleLogic()=0;

    virtual ~MainLogic_Base();
};

class MainLogic_gameRunning : public MainLogic_Base
{
public:
    MainLogic_gameRunning();
    void handleLogic() override;
private:
    std::future<sf::Texture> textureFuture;
};



class MainLogic_NULL : public MainLogic_Base
{
public:
    void handleLogic() override;
};