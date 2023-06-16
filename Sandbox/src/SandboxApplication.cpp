#include "Sandbox.h"
#include <iostream>
int main()
{
    std::cout << "Hello" << std::endl;
    std::cin.get();
    std::unique_ptr<Sandbox> app=std::unique_ptr<Sandbox>(new Sandbox());
    app->Run();
    return 0;
}