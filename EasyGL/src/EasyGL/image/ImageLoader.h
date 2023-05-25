#pragma once
#include <string>
class ImageLoader
{
public:
    // support jpg png
    static unsigned char* Load(const std::string& path,int& width,int& height,int& channel);
    static void Free(unsigned char* img);
};


