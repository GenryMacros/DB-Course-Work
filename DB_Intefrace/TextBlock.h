#pragma once
#include "UI_Elem.h"
class TextBlock :public UI_Elem {
public:
    TextBlock(const char* fontSource,const char* Mes,int fontSize,glm::vec3 sc, glm::vec3 pos, Shader* shade,Text* tex=nullptr, GLuint VAO=0, GLuint VBO=0) :UI_Elem(sc, pos, shade) {
   
        mes = Mes;
        if (!tex) {
        /*    GLuint VAO, VBO;
            glGenVertexArrays(1, &VAO);
            glGenBuffers(1, &VBO);
            glBindVertexArray(VAO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0); */

            text = new Text(fontSource, "../ShadersTXT/text.v.txt", "../ShadersTXT/text.f.txt", fontSize, VAO, VBO);
        }
           
        else
            text = tex;
    }
    ~TextBlock() {
       text=nullptr;
    }
    void Draw() {
        DrawBlock();
        DrawText();
    }
    void DrawText() {
        text->DraWText(mes, position.x - 0.2, position.y - 0.02f, 1.0f, textColor);
    }
    void DrawBlock() {
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
    void setTextColor(glm::vec3 newCol) {
        textColor = newCol;
    }
    void setText(std::string& str) {
        mes = str;
    }
private:
    
    glm::vec3 textColor=glm::vec3(1.0f,1.0f,1.0f);
    std::string mes;
    Text* text;
};