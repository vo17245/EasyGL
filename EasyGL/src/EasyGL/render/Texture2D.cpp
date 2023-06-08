#include "image/ImageLoader.h"
#include "Texture2D.h"
#include "platform/renderer/opengl/GLCall.h"
#include "EasyGLDebug.h"



Texture2D::Texture2D(const std::string& path)
{
    //GLCall(glActiveTexture(GL_TEXTURE0));
    // create and bind texture
    GLCall(glGenTextures(1, &m_RendererID));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));  
    // set the texture wrapping/filtering options (on the currently bound texture object)
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));	
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    // load image
    int width, height, nrChannels;
    unsigned char* data=ImageLoader::Load(path,width,height,nrChannels);
    ASSERT(data!=nullptr,"Failed to laod texture");
    // upload image to gpu
    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data));
    GLCall(glGenerateMipmap(GL_TEXTURE_2D)); 

    // free imagers
    ImageLoader::Free(data);
}
Texture2D::Texture2D(const JpgImage& jpg)
{
    // create and bind texture
    GLCall(glGenTextures(1, &m_RendererID));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));  
    // set the texture wrapping/filtering options (on the currently bound texture object)
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));	
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    // upload image to gpu
    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, jpg.GetWidth(), jpg.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, jpg.GetData()));
    GLCall(glGenerateMipmap(GL_TEXTURE_2D));
}

Texture2D::Texture2D(const PngImage& png)
{
    // create and bind texture
    GLCall(glGenTextures(1, &m_RendererID));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));  
    // set the texture wrapping/filtering options (on the currently bound texture object)
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));	
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    // upload image to gpu
    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, png.GetWidth(), png.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, png.GetDate()));
    GLCall(glGenerateMipmap(GL_TEXTURE_2D));
}


Texture2D::Texture2D(size_t width,size_t height)
{
    ASSERT(false,"not implemented");
}

Texture2D::~Texture2D()
{
    GLCall(glDeleteTextures(1,&m_RendererID));
}


void Texture2D::Bind()
{
    GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));  
}

void Texture2D::Unbind()
{
    GLCall(glBindTexture(GL_TEXTURE_2D, 0)); 
}

