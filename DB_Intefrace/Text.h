#pragma once
#include "Shader.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
class Text {
	struct Character {
		GLuint     TextureID; // ID текстуры глифа
		glm::ivec2 Size;      // Размеры глифа
		glm::ivec2 Bearing;   // Смещение верхней левой точки глифа
		GLuint     Advance;   // Горизонтальное смещение до начала следующего глифа
	};
public:
	Text(const char* fontPath, const char* vertexPath, const char* fragmentPath, int fontSize, GLuint& vao, GLuint& vbo);
	~Text() {
		std::map<GLchar, Character> ::iterator it = Characters.begin();
	
		for (int i = 0; it != Characters.end(); it++, i++) {  // выводим их
		
			glDeleteTextures(1, &it->second.TextureID);
		}
		Characters.clear();
	}
	void DraWText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
private:
	int VAO;
	int VBO;
	std::map<GLchar, Character> Characters;
	Shader texShade;
	glm::vec3 texColor = glm::vec3(1.0f, 1.0f, 1.0f);
};