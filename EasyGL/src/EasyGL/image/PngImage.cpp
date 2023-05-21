#include "PngImage.h"
#include "ImageLoader.h"

PngImage::PngImage(const std::string& path)
{
    m_Data=ImageLoader::Load(path,m_Width,m_Height,m_Channel);
}

PngImage::~PngImage()
{
    ImageLoader::Free(m_Data);
}