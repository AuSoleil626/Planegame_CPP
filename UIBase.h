#pragma once

class UIBase
{
public:
    explicit UIBase();
    virtual ~UIBase()=0;
public:
    virtual void render() =0; 
    virtual void update() =0;
    virtual void eventHandle()=0;
};
