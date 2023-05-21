#pragma once
#include <string>

class JpgImage
{
private:
    int m_Width;
    int m_Height;
    int m_Channel;
    unsigned char* m_Data;
public:
    JpgImage(JpgImage&& img)=delete;
    JpgImage(const JpgImage& img)=delete;
    JpgImage& operator=(JpgImage&& img)=delete;
    JpgImage& operator=(const JpgImage& img)=delete;

    JpgImage(const std::string& path);
    ~JpgImage();
    inline unsigned char* GetDate()const{return m_Data;}
    inline int GetWidth()const{return m_Width;}
    inline int GetHeight()const{return m_Height;}
    inline int GetChannel()const{return m_Channel;}
};