#include "JpgImage.h"
#include "ImageLoader.h"
#include <string.h>

JpgImage::JpgImage(const std::string& path)
{
    unsigned char* p=ImageLoader::Load(path,m_Width,m_Height,m_Channel);
    size_t size=m_Width*m_Height*m_Channel;
    m_Data=new unsigned char[size];
    memcpy(m_Data,p,size);
    ImageLoader::Free(p);
}

JpgImage::~JpgImage()
{
    if(m_Data!=nullptr)
        delete m_Data;
}

JpgImage::JpgImage(JpgImage&& jpg)
    :m_Width(jpg.m_Width),
    m_Height(jpg.m_Height),
    m_Channel(jpg.m_Channel),
    m_Data(jpg.m_Data)
{
    jpg.m_Data=nullptr;
}


JpgImage::JpgImage(const JpgImage& jpg)
{
    m_Width=jpg.m_Width;
    m_Height=jpg.m_Height;
    m_Channel=jpg.m_Channel;
    size_t dataSize=jpg.GetDataSize();
    m_Data=new unsigned char[dataSize];
    memcpy(m_Data,jpg.GetData(),dataSize);
}
JpgImage& JpgImage::operator=(JpgImage&& jpg)
{
    if(m_Data!=nullptr)
        delete m_Data;
    m_Width=jpg.m_Width;
    m_Height=jpg.m_Height;
    m_Channel=jpg.m_Channel;
    m_Data=jpg.GetData();
    jpg.m_Data=nullptr;
    return *this;
}
JpgImage& JpgImage::operator=(const JpgImage& jpg)
{
    if(m_Data!=nullptr)
        delete m_Data;
    m_Width=jpg.m_Width;
    m_Height=jpg.m_Height;
    m_Channel=jpg.m_Channel;
    size_t dataSize=jpg.GetDataSize();
    m_Data=new unsigned char[dataSize];
    memcpy(m_Data,jpg.GetData(),dataSize);
    return *this;
}

JpgImage::JpgImage(size_t width,size_t height,size_t channel)
    :m_Width(width),m_Height(height),m_Channel(channel)
{
    m_Data=new unsigned char[width*height*channel];
}