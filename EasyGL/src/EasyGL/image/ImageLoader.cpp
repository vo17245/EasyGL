#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include "ImageLoader.h"
#include "EasyGL/EasyGLDebug.h"

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

