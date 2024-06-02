#pragma once

class MainLogic_Base
{
public:
    virtual void handleLogic()=0;

    virtual ~MainLogic_Base();
};
class MainLogic : public MainLogic_Base
{
public:
    void handleLogic() override;
};
class MainLogic_NULL : public MainLogic_Base
{
public:
    void handleLogic() override;
};