#pragma once
#include <future>
#include <SFML/Graphics/Texture.hpp>

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
    std::future<std::shared_ptr<BulletFactory_Player>> load_bullet_factory_player_;

    std::shared_ptr<BulletFactory_Player> bullet_factory_player_;

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