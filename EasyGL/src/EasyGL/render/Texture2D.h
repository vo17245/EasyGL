#pragma once
#include <string>
#include <image/JpgImage.h>
#include <image/PngImage.h>

class Texture2D
{
private:
    uint32_t m_RendererID;
public:
    Texture2D(const std::string& path);
    Texture2D(size_t width,size_t height);
    Texture2D(const JpgImage& jpg);
    Texture2D(const PngImage& png);
    void Bind();
    void Unbind();
    ~Texture2D();
};