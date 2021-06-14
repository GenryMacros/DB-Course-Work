#pragma once
#include "UI_Elem.h"

class selectionCircle :public UI_Elem {
	class Circle {
	public:
		Circle() = default;
		void Create(float radius,glm::vec3 nColor,int segAmout) {
			r = radius;
			Color = nColor;
			amountSegments = segAmout;
		}
		glm::vec3 Color;
		float r;
		int amountSegments;
	};
public:
	selectionCircle(glm::vec3 sc, glm::vec3 pos, Shader* shade,float radius,float circleDots,GLuint& vao,GLuint& vbo) :UI_Elem(sc, pos, shade) {
		r = radius;
		amountSegments= circleDots;
		selectCircle.Create(r*0.8,glm::vec3(0.3,0.3,0.3),circleDots*0.8);
	

		selectionText = new Text(FONT, "../ShadersTXT/text.v.txt", "../ShadersTXT/text.f.txt",18,vao,vbo);
	}
	void SetTextAData(std::string& select,int data) {
		rText = select;
		SQLIdData = data;
	}
	void SetTextColor(float r,float g,float b) {
		TextColor = glm::vec3(r,g,b);
	}
	void SetTextPosition(float x,float y) {
		TextPos = glm::vec2(position.x + x, position.y + y);
	}
	void Draw() {
		shader->use();
		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, getPosition());
		transform = glm::scale(transform, getScale());
		getShader()->setMat4("transform", transform);
		getShader()->setVec3("aColor", lineColor.x, lineColor.y, lineColor.z);

		glBegin(GL_LINE_STRIP); //BEGIN CIRCLE // center of circle
		for (int i = 0; i <= amountSegments; i++) {
			glVertex2f(
				(position.x + (r * cos(i * twicePi / 20))), (position.y + (r * sin(i * twicePi / 20)))
			);
		}
		glEnd();
		if (isSelected) {
			shader->setVec3("aColor", selectCircle.Color.x, selectCircle.Color.x, selectCircle.Color.z);
			glBegin(GL_TRIANGLE_FAN);
			glVertex2f(position.x, position.y);
			for (int i = 0; i <= selectCircle.amountSegments; i++) {
				glVertex2f(
					(position.x + (selectCircle.r * cos(i * twicePi / 20))), (position.y + (selectCircle.r * sin(i * twicePi / 20)))
				);
			}
			glEnd();
		}
		selectionText->DraWText(rText,TextPos.x,TextPos.y,1.0f, TextColor);
	}
	void DrawRed() {
		
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_TRIANGLE_FAN); 
		glVertex2f(position.x, position.y);
		for (int i = 0; i <= amountSegments; i++) {
			glVertex2f(
				(position.x + (r * cos(i * twicePi / 20))), (position.y + (r * sin(i * twicePi / 20)))
			);
		}
		glEnd();
	}
	bool Selected() {
		return isSelected;
	}
	bool handleClick(glm::vec2 mousePos) {
		shader->use();
		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, getPosition());
		transform = glm::scale(transform, getScale());
		getShader()->setMat4("transform", transform);
		getShader()->setVec3("aColor", lineColor.x, lineColor.y, lineColor.z);
		shader->setBool("isClick", 1);
		bool ret = false;
		DrawRed();
		GLubyte* arr = new GLubyte[4];
		glReadPixels(mousePos.x, mousePos.y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, arr);
		

		if (arr[0] == 255) {
			isSelected = true;
			ret = true;
		}
		else
			isSelected = false;

		shader->setBool("isClick", 0);
		glClearColor(0.3f, 0.7f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		delete[] arr;
		return ret;
	}
	int getSQLidData() {
		return SQLIdData;
	}
private:
	Circle selectCircle;
	std::string rText;
	Text* selectionText;
	glm::vec3 TextColor=glm::vec3(0,0,0);
	glm::vec2 TextPos;
	int SQLIdData;
	bool isSelected = false;
	float r;
	int amountSegments;
	double twicePi = 2.0 * 3.142;
};