#pragma once
#include "InputBlock.h"
class Button :public UI_Elem {
public:
    Button(){}
    Button(void (*func)(list<Input*>& lst, std::string& reqTex),glm::vec3 sc, glm::vec3 pos,Shader* shade,std::string text,const char* fontSource,GLuint& VAO,GLuint& VBO):UI_Elem(sc, pos, shade){
  /*      GLuint VAO, VBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0); */
        buttonText = text;
        activatingFunction = func;
        tex = new Text(fontSource, "../ShadersTXT/text.v.txt","../ShadersTXT/text.f.txt" ,20,VAO,VBO);
    }
    ~Button() {
        delete tex;
       
    }
    void Select(list<Input*>& lst) {
       (*activatingFunction)(lst,reqTex);
     
    }
    void Draw() {
  
        DrawBlock();
        DrawBlockText();
    }
    void DrawBlock() {
        getShader()->use();
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, getPosition());
        transform = glm::scale(transform, getScale());
        getShader()->setMat4("transform", transform);
        getShader()->setVec3("aColor", fillColor.x, fillColor.y, fillColor.z);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_QUADS);
        glVertex2f(-0.4f, 0.4f);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f(0.4f, -0.4f);
        glVertex2f(0.4f, 0.4f);
        glEnd();
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
    void DrawBlockText() {

        tex->DraWText(buttonText, textPosition.x, textPosition.y,1.0f,textColor);
    }
    bool handleClick(glm::vec2 mousePos,list<Input*>& lst) {
        getShader()->use();
        getShader()->setBool("isClick", 1);
        bool ret = false;
        DrawBlock();
        GLubyte* arr = new GLubyte[4];
        glReadPixels(mousePos.x, mousePos.y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, arr);
        getShader()->setBool("isClick", 0);

        if (arr[0] == 255) {  
            Select(lst);
            ret = true;
        }
         
      
        glClearColor(0.3f, 0.7f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        delete[] arr;
        return ret;
    }
    bool handleClick(glm::vec2 mousePos) {
        getShader()->use();
        getShader()->setBool("isClick", 1);
        bool ret = false;
        DrawBlock();
        GLubyte* arr = new GLubyte[4];
        glReadPixels(mousePos.x, mousePos.y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, arr);

        getShader()->setBool("isClick", 0);
        glClearColor(0.3f, 0.7f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        if (arr[0] == 255) {
            list<Input*> in;
            Select(in);
            ret = true;
        }

     
      
        delete[] arr;
        return ret;
    }
    void setTexPos(glm::vec2 pos) {
        textPosition = pos;
    }
    void setTexColor(glm::vec3 col) {
        textColor = col;
    }
    void setReqTex(std::string str) {
        reqTex = str;
    }
private:
    Text* tex;
    std::string reqTex;
    std::string buttonText;
    glm::vec3 textColor=glm::vec3(1.0f,1.0f,1.0f);
    glm::vec2 textPosition=glm::vec2(position.x,position.y);
    void (*activatingFunction)(list<Input*>& lst, std::string& reqTex)=nullptr;
};
