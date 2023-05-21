#pragma once
class Application
{
public:
    Application(){}
    virtual ~Application(){}
    virtual void Run()=0;
};