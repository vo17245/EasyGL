#include "DngImage.h"
#include "ImageLoader.h"

DngImage::DngImage(const std::string& path)
{
    ImageLoader::LoadDng(path,m_Width,m_Height,m_BitsPerPixel,m_Pattern);
}

DngImage::DngImage(const char* data,size_t size)
{
    ImageLoader::LoadDngFromMemory(data,size,m_Width,m_Height,m_BitsPerPixel,m_Pattern);
}

DngImage::DngImage(DngImage&& dng)
    :m_Width(dng.m_Width),
    m_Height(dng.m_Height),
    m_BitsPerPixel(dng.m_BitsPerPixel),
    m_Pattern(dng.m_Pattern),
    m_Data(std::move(dng.m_Data)){}