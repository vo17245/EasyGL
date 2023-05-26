#pragma once
#include <string>
#include <vector>

#include "DngPattern.h"

class ImageLoader
{
public:
    // support jpg png bmp
    static unsigned char* Load(const std::string& path,int& width,int& height,int& channel);
    static void Free(unsigned char* img);
    static std::vector<unsigned char> LoadDng(const std::string& path,int& width,int& height,int& bitsPerPixel,DngPattern& pattern);
    static std::vector<unsigned char> LoadDngFromMemory(const char* rawData,size_t size,int& width,int& height,int& bitsPerPixel,DngPattern& pattern);

};
