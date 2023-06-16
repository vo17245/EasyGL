
#include "Shader.h"
#include "platform/renderer/opengl/GLCall.h"
#include <fstream>
#include "Log.h"
#include "Buffer.h"
#include <iostream>

static Buffer LoadFile(const std::string& filepath)
{
    Buffer buf;
    struct stat statbuf;
    int ret =stat(filepath.c_str(), &statbuf);
    if (ret != 0)
    {
        ERROR("Failed to load {0}", filepath);
        return buf;
    }
        
    FILE* fp;
    fp = fopen(filepath.c_str(), "rb");
    buf.Push(statbuf.st_size, [statbuf,fp](char* buffer) 
        {
            fread(buffer, statbuf.st_size, 1, fp);
        }
    );
    fclose(fp);
    return buf;
}

static uint32_t CompileShader(uint32_t type, const Buffer& src)
{
    GLCall(uint32_t id = glCreateShader(type));
    const char* src_data = src.GetData();
    GLCall(glShaderSource(id, 1, &src_data, nullptr));
    GLCall(glCompileShader(id));
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = new char[length];
        
        glGetShaderInfoLog(id, length, &length, message);
        ERROR("[OpenGL] {0} Shader Compile Error \n{1}", type==GL_VERTEX_SHADER?"Vertex":"Fragment", message);
        delete[] message;
    }
    return id;
}
static uint32_t CreateShader(const Buffer& vs, const Buffer& fs)
{
    int32_t vs_id = CompileShader(GL_VERTEX_SHADER, vs);
    int32_t fs_id = CompileShader(GL_FRAGMENT_SHADER, fs);
    uint32_t program_id = glCreateProgram();
    GLCall(glAttachShader(program_id, vs_id));
    GLCall(glAttachShader(program_id, fs_id));
    GLCall(glLinkProgram(program_id));
    GLCall(glValidateProgram(program_id));
    GLCall(glDeleteShader(vs_id));
    GLCall(glDeleteShader(fs_id));
    return program_id;
}
static uint32_t CompileShader(uint32_t type, const std::vector<char>& src)
{
    GLCall(uint32_t id = glCreateShader(type));
    const char* src_data = src.data();
    GLCall(glShaderSource(id, 1, &src_data, nullptr));
    GLCall(glCompileShader(id));
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = new char[length];
        
        glGetShaderInfoLog(id, length, &length, message);
        ERROR("[OpenGL] {0} Shader Compile Error \n{1}", type==GL_VERTEX_SHADER?"Vertex":"Fragment", message);
        delete[] message;
    }
    return id;
}
static uint32_t CreateShader(const std::vector<char>& vs, const std::vector<char>& fs)
{
    int32_t vs_id = CompileShader(GL_VERTEX_SHADER, vs);
    int32_t fs_id = CompileShader(GL_FRAGMENT_SHADER, fs);
    uint32_t program_id = glCreateProgram();
    GLCall(glAttachShader(program_id, vs_id));
    GLCall(glAttachShader(program_id, fs_id));
    GLCall(glLinkProgram(program_id));
    GLCall(glValidateProgram(program_id));
    GLCall(glDeleteShader(vs_id));
    GLCall(glDeleteShader(fs_id));
    return program_id;
}
Shader::Shader(const std::string& vertexshader_filepath, const std::string& fragmentshader_filepath)
{
    char end = 0;
    Buffer vs = LoadFile(vertexshader_filepath);
    vs.Push(1,&end);
    Buffer fs = LoadFile(fragmentshader_filepath);
    fs.Push(1, &end);
    m_RendererID = CreateShader(vs, fs);
    Bind();
}
Shader::~Shader()
{
    GLCall(glDeleteProgram(m_RendererID));
}
void Shader::Bind()const
{
    GLCall(glUseProgram(m_RendererID));
}
void Shader::Unbind()const
{
    GLCall(glUseProgram(0));
}
void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)const
{
    int32_t location = GetLocation(name);
    GLCall(glUniform4f(location, v0, v1, v2, v3));
}
void Shader::SetUniformMat4f(const std::string& name, const Eigen::Matrix4f& mat)const
{
    int32_t location = GetLocation(name);
    GLCall(glUniformMatrix4fv(location, 1, GL_FALSE, mat.data()));
}
int32_t Shader::GetLocation(const std::string& name)const
{
    auto iter = m_LocationLocalCache.find(name);
    if (iter != m_LocationLocalCache.end())
        return m_LocationLocalCache[name];
    GLCall(int32_t location=glGetUniformLocation(m_RendererID, name.c_str()));
    if (location == -1)
    {
        ERROR("Can not find uniform {0}", name);
        return location;
    }
    else
    {
        m_LocationLocalCache[name] = location;
        return location;
    }
    
}


Shader::Shader(const std::vector<char>& vertexShader,const std::vector<char>& fragmentShader)
{
    m_RendererID = CreateShader(vertexShader, fragmentShader);
}