#pragma once
#include <string>
class PngImage
{
private:
    int m_Width;
    int m_Height;
    int m_Channel;
    unsigned char* m_Data;
public:
    PngImage(PngImage&& img)=delete;
    PngImage(const PngImage& img)=delete;
    PngImage& operator=(PngImage&& img)=delete;
    PngImage& operator=(const PngImage& img)=delete;

    PngImage(const std::string& path);
    ~PngImage();
    inline unsigned char* GetDate()const{return m_Data;}
    inline int GetWidth()const{return m_Width;}
    inline int GetHeight()const{return m_Height;}
    inline int GetChannel()const{return m_Channel;}
};