#pragma once
#include "Eigen/Core"

class Shader
{
public:
	Shader(const std::string& vertexshader_filepath,const std::string& fragmentshader_filepath);
	~Shader();
	void Bind()const;
	void Unbind()const;
	void SetUniform4f(const std::string& name,float v0, float v1, float v2, float v3)const;
	void SetUniformMat4f(const std::string& name,const Eigen::Matrix4f& mat)const;
private:
	uint32_t m_RendererID;
	int32_t GetLocation(const std::string& name)const;
	mutable std::unordered_map<std::string, uint32_t> m_LocationLocalCache;
};



