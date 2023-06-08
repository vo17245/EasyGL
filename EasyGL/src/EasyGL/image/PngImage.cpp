#include "PngImage.h"
#include "ImageLoader.h"

PngImage::PngImage(const std::string& path)
{
    m_Data=ImageLoader::Load(path,m_Width,m_Height,m_Channel);
}

PngImage::~PngImage()
{
    if(m_Data!=nullptr)
        ImageLoader::Free(m_Data);
}

PngImage::PngImage(PngImage&& img)
    :m_Width(img.m_Width),
    m_Height(img.m_Height),
    m_Channel(img.m_Channel),
    m_Data(img.m_Data)
{
    img.m_Data=nullptr;
}