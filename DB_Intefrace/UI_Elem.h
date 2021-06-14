#pragma once
#include "Text.h"
#include <SFML/Window.hpp>
#define BUTTON_fSHADER_PATH "../ShadersTXT/inter.f.txt"
#define BUTTON_vSHADER_PATH "../ShadersTXT/inter.v.txt"
#define FONT "Font/1.ttf"
#define STANDART_fSHADER_PATH "../ShadersTXT/first.f.txt"
#define STANDART_vSHADER_PATH "../ShadersTXT/first.v.txt"
#define BACKGROUND_V "../ShadersTXT/alphaBlock.v.txt"
#define BACKGROUND_F "../ShadersTXT/alphaBlock.f.txt"

class UI_Elem {
public:
	UI_Elem() = default;
	UI_Elem(glm::vec3 sc, glm::vec3 pos,Shader* shade) {
		scale = sc;
		position = pos;
		shader = shade;
	}
	~UI_Elem() {
		shader = nullptr;
	}
	void setColors(glm::vec3 fill, glm::vec3 line) {
		fillColor = fill;
		lineColor = line;
	}
	void setPosition(glm::vec3 pos) {
		position = pos;
	}
	void setScale(glm::vec3 sc) {
		scale = sc;
	}
	Shader* getShader() {
		return shader;
	}
	glm::vec3& getFillColor() {
		return fillColor;
	}
	glm::vec3& getLineColor() {
		return lineColor;
	}
	glm::vec3& getScale() {
		return scale;
	}
	glm::vec3& getPosition() {
		return position;
	}
	void ResetShader(Shader* shade) {
		shader = shade;
	}
protected:
	Shader* shader;
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 fillColor = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 lineColor = glm::vec3(1.0f, 1.0f, 1.0f);
};