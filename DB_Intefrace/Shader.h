#pragma once
#include <GL/glew.h> 
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	unsigned int ID;
	Shader() = default;
	void CreateShader(const char* vertexPath, const char* fragmentPath);
	~Shader();
	Shader(const Shader& cop);
	void use();
	void setFloat(const std::string Varname, float value);
	void setVec2(const std::string Varname, float x, float y);
	void setVec3(const std::string Varname, float x, float y, float z);
	void setVec4(const std::string Varname, float x, float y, float z, float j);
	void setMat4(const std::string Varname, glm::mat4 matrix);
	void setInt(const std::string Varname, unsigned int value);
	void setBool(const std::string Varname, bool value);
};
