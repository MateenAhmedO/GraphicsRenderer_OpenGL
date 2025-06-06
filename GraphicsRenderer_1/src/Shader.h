#pragma once

#include<string>
#include<unordered_map>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	std::unordered_map < std::string, int > m_UniformLocationCache;

	unsigned int GetUniformLocation(const std::string& name);
	bool CompileShader();
	unsigned int CompileShader(unsigned int type, const std::string& source);
	ShaderProgramSource ParseShader(const std::string& filePath);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;
	void SetUniform4f(const std::string& name , float v0 , float v1 , float f2 , float f3);
};