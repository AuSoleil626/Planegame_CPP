#pragma once

class UIBase
{
public:
    UIBase();
    virtual ~UIBase();
public:
    virtual void render() =0; 
    virtual void update() =0;
    virtual void eventHandle()=0;
};
