#include "Sandbox.h"
#include <iostream>
int main()
{
    std::unique_ptr<Sandbox> app=std::unique_ptr<Sandbox>(new Sandbox());
    app->Run();
    return 0;
}