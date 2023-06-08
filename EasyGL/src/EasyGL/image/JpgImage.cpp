#include "JpgImage.h"
#include "ImageLoader.h"

JpgImage::JpgImage(const std::string& path)
{
    m_Data=ImageLoader::Load(path,m_Width,m_Height,m_Channel);
}

JpgImage::~JpgImage()
{
    if(m_Data!=nullptr)
        ImageLoader::Free(m_Data);
}

JpgImage::JpgImage(JpgImage&& jpg)
    :m_Width(jpg.m_Width),
    m_Height(jpg.m_Height),
    m_Channel(jpg.m_Channel),
    m_Data(jpg.m_Data)
{
    jpg.m_Data=nullptr;
}