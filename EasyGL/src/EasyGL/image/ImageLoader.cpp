#define STB_IMAGE_IMPLEMENTATION
#define TINY_DNG_LOADER_IMPLEMENTATION
#define TINY_DNG_LOADER_NO_STB_IMAGE_INCLUDE
#include "stb/stb_image.h"
#include "ImageLoader.h"
#include "EasyGLDebug.h"
#include <string>
#include <vector>
#include <tinydng/tiny_dng_loader.h>
#include "Log.h"

static DngPattern GetDngPattern(int a,int b,int c,int d)
{
    if(a==0&&b==1&&c==1&&d==2)
    {
        return DngPattern::RGGB;
    }
    else if(a==2&&b==1&&c==1&&d==0)
    {
        return DngPattern::BGGR;
    }
    else
    {
        std::stringstream ss;
        ss<<"unknown dng pattern "<<a<<" "<<b<<" "<<c<<" "<<d;
        ASSERT(false,ss.str());
    }
    return DngPattern::UNKNOWN;
}

unsigned char* ImageLoader::Load(const std::string& path,int& width,int& height,int& channel)
{
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &channel, 0);
    ASSERT(data!=nullptr,"Failed to laod texture");
    return data;
}

void ImageLoader::Free(unsigned char* img)
{
    stbi_image_free(img);
}



std::vector<unsigned char> ImageLoader::LoadDng(const std::string& path,int& width,int& height,int& bitsPerPixel,DngPattern& pattern)
{
    std::string warn, err;
    std::vector<tinydng::DNGImage> images;
    std::vector<tinydng::FieldInfo> custom_field_lists;
    bool ret = tinydng::LoadDNG(path.c_str(), custom_field_lists, &images, &warn, &err);
    ASSERT(warn.empty(),warn);
    ASSERT(err.empty(),err);
    ASSERT(ret,"can not load dng image");
    tinydng::DNGImage& image = images[0];
    width = image.width;
    height = image.height;
    bitsPerPixel = image.bits_per_sample;
    std::vector<unsigned char> data = std::move(image.data);
    pattern=GetDngPattern(image.cfa_pattern[0][0],image.cfa_pattern[0][1],image.cfa_pattern[1][0],image.cfa_pattern[1][1]);
    return data;
}

std::vector<unsigned char> ImageLoader::LoadDngFromMemory(const char* rawData,size_t size,int& width,int& height,int& bitsPerPixel,DngPattern& pattern)
{
    std::string warn, err;
    std::vector<tinydng::DNGImage> images;
    std::vector<tinydng::FieldInfo> custom_field_lists;
    bool ret =tinydng::LoadDNGFromMemory(rawData,size,custom_field_lists, &images, &warn, &err);
    ASSERT(warn.empty(),warn);
    ASSERT(err.empty(),err);
    ASSERT(ret,"can not load dng image");
    tinydng::DNGImage& image = images[0];
    width = image.width;
    height = image.height;
    bitsPerPixel = image.bits_per_sample;
    std::vector<unsigned char> data = std::move(image.data);
    pattern=GetDngPattern(image.cfa_pattern[0][0],image.cfa_pattern[0][1],image.cfa_pattern[1][0],image.cfa_pattern[1][1]);
    return data;
}