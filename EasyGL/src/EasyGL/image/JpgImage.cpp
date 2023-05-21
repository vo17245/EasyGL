#include "JpgImage.h"
#include "ImageLoader.h"

JpgImage::JpgImage(const std::string& path)
{
    m_Data=ImageLoader::Load(path,m_Width,m_Height,m_Channel);
}

JpgImage::~JpgImage()
{
    ImageLoader::Free(m_Data);
}