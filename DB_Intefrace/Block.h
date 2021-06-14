#pragma once
#include "UI_Elem.h"
class Block:public UI_Elem {
public:
	Block(glm::vec3 sc, glm::vec3 pos, Shader* shade):UI_Elem(sc, pos, shade) {}
	void Draw() {
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

};
