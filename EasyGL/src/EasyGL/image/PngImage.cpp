#include "PngImage.h"
#include "ImageLoader.h"
#include <string.h>

PngImage::PngImage(const std::string& path)
{

    unsigned char* p=ImageLoader::Load(path,m_Width,m_Height,m_Channel);
    size_t size=m_Width*m_Height*m_Channel;
    m_Data=new unsigned char[size];
    memcpy(m_Data,p,size);
    ImageLoader::Free(p);
}

PngImage::~PngImage()
{
    if(m_Data!=nullptr)
        delete m_Data;
}

PngImage::PngImage(PngImage&& img)
    :m_Width(img.m_Width),
    m_Height(img.m_Height),
    m_Channel(img.m_Channel),
    m_Data(img.m_Data)
{
    img.m_Data=nullptr;
}