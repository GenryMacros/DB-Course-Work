#include "Shader.h"

void Shader::CreateShader(const char* vertexPath, const char* fragmentPath) {
	//const char* frag;
	std::string verCode;
	std::string fragCode;

	std::ifstream vertexShaderFile;
	std::ifstream fragmentShaderFile;

	std::stringstream vertexShaderStream, fragmentShaderStream;
	vertexShaderFile.open(vertexPath);
	fragmentShaderFile.open(fragmentPath);
	if (!vertexShaderFile.is_open()) std::cout << "ERROR:Vertex shader source hasnt open!" << std::endl;
	if (!fragmentShaderFile.is_open()) std::cout << "ERROR:Fragment shader source hasnt open!" << std::endl;
	vertexShaderStream << vertexShaderFile.rdbuf();
	fragmentShaderStream << fragmentShaderFile.rdbuf();
	verCode = vertexShaderStream.str();
	fragCode = fragmentShaderStream.str();

	const char* verS = verCode.c_str();
	const char* fragS = fragCode.c_str();

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &verS, NULL);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragS, NULL);
	glCompileShader(fragmentShader);


	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);


}
Shader::Shader(const Shader& cop) {
	ID = cop.ID;
}
Shader::~Shader() {
	glDeleteProgram(ID);
	
}
void Shader::use() {
	glUseProgram(ID);
}

void Shader::setFloat(const std::string Varname, float value) {
	int varLoc = glGetUniformLocation(ID, Varname.c_str());
	glUniform1f(varLoc, value);
}
void Shader::setVec2(const std::string Varname, float x, float y) {
	int varLoc = glGetUniformLocation(ID, Varname.c_str());
	glUniform2f(varLoc, x, y);


}
void Shader::setVec3(const std::string Varname, float x, float y, float z) {
	int varLoc = glGetUniformLocation(ID, Varname.c_str());
	glUniform3f(varLoc, x, y, z);


}
void Shader::setVec4(const std::string Varname, float x, float y, float z, float j) {
	int varLoc = glGetUniformLocation(ID, Varname.c_str());
	glUniform4f(varLoc, x, y, z, j);


}
void Shader::setMat4(const std::string Varname, glm::mat4 matrix) {
	int varLoc = glGetUniformLocation(ID, Varname.c_str());
	glUniformMatrix4fv(varLoc, 1, GL_FALSE, glm::value_ptr(matrix));
}
void Shader::setInt(const std::string Varname, unsigned int value) {
	int varLoc = glGetUniformLocation(ID, Varname.c_str());
	glUniform1i(varLoc, value);
}
void Shader::setBool(const std::string Varname, bool value) {
	int varLoc = glGetUniformLocation(ID, Varname.c_str());
	glUniform1i(varLoc, value);
}