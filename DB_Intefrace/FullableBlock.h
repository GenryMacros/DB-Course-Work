#pragma once
#include "UI_Elem.h"
class FullableBlock:public UI_Elem {
public:
	FullableBlock(glm::vec3 sc, glm::vec3 pos, Shader* shade,int fillNum,Text* text) :UI_Elem(sc, pos, shade), fillNum((float)fillNum/100) {
    
        tex = text;
        fillText = std::to_string(fillNum) + "/100";
    }
	
	void Draw() {
		DrawBackGround();
		DrawFillency();
	}
	void DrawBackGround() {
        getShader()->use();
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, getPosition());
        transform = glm::scale(transform, getScale());
        getShader()->setMat4("transform", transform);
        glm::vec3 fillColor = getFillColor();
        getShader()->setVec3("aColor", fillColor.x, fillColor.y, fillColor.z);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_QUADS);
        glVertex2f(-0.4f, 0.4f);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f(0.4f, -0.4f);
        glVertex2f(0.4f, 0.4f);
        glEnd();
        glm::vec3 lineColor = getLineColor();
        getShader()->setVec3("aColor", lineColor.x, lineColor.y, lineColor.z);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBegin(GL_QUADS);
        glVertex2f(-0.4f, 0.4f);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f(0.4f, -0.4f);
        glVertex2f(0.4f, 0.4f);
        glEnd();
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
    void SetFillencyColor(glm::vec3 col) {
        FillColor = col;
    }
	void DrawFillency() {
        const float g = 0.4 * scale.x;
        float xScale = fillNum*(scale.x);
        getShader()->use();
        glm::mat4 transform = glm::mat4(1.0f);
        //-fillNum*(-fillNum * (scale.x)+scale.x)+ (-fillNum * (scale.x) + scale.x)/((1-fillNum)*20)
        transform = glm::translate(transform, glm::vec3(-0.4*scale.x+0.4*xScale+position.x,position.y-0.001,position.z));
        transform = glm::scale(transform, glm::vec3(xScale,scale.y-0.01,scale.z));
        getShader()->setMat4("transform", transform);
        glm::vec3 fillColor = getFillColor();
        getShader()->setVec3("aColor", FillColor.x, FillColor.y, FillColor.z);

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_QUADS);
        glVertex2f(-0.4f, 0.4f);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f(0.4f, -0.4f);
        glVertex2f(0.4f, 0.4f);
        glEnd();

        tex->DraWText(fillText, position.x-0.07f, position.y-0.02f, 1.0f, textColor);
	}
    void SetTexColor(glm::vec3 col) {
        textColor = col;
    }
private:
    glm::vec3 textColor;
	glm::vec3 backGroundColor;
	glm::vec3 FillColor;
	float fillNum;
    Text* tex;
    std::string fillText;

};
