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
    JpgImage(JpgImage&& img);
    JpgImage(const JpgImage& jpg);
    JpgImage& operator=(JpgImage&& jpg);
    JpgImage& operator=(const JpgImage& jpg);

    JpgImage(const std::string& path);
    ~JpgImage();
    inline const unsigned char* GetData()const{return m_Data;}
    inline unsigned char* GetData(){return m_Data;}
    inline int GetWidth()const{return m_Width;}
    inline int GetHeight()const{return m_Height;}
    inline int GetChannel()const{return m_Channel;}
    inline size_t GetDataSize()const{return m_Channel*m_Width*m_Height;}
};