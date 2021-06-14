#pragma once
#include "UI_Elem.h"
#include "Clock.h"
#include "List.h"
class Input:public UI_Elem {
public:
    Input(glm::vec3 sc, glm::vec3 pos, Shader* shade, std::string text, const char* fontSource, GLuint& VAO, GLuint& VBO) :UI_Elem(sc, pos, shade) {
     /*   GLuint VAO, VBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0); */

        emptyText =' '+ text;
        tex = new Text(fontSource, "../ShadersTXT/text.v.txt", "../ShadersTXT/text.f.txt", 20, VAO, VBO);  
       // standartLineColor=lineColor;
    }
    ~Input() {
        delete tex;
    }
    void Select() {
        lineColor = selectedLineColor;
        isSelected = true;
    }
    void unSelect() {
        lineColor = standartLineColor;
        isSelected = false;
        waitTimeLeft = 0;
        timeLeft = 0;
    }
    void Draw() {

        DrawBlock();
        DrawText();
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
    void DrawText() {
        if (isSelected) {
            if (waitTimeLeft < waitTime) {
                if (inputText.length() == 0) {

                    tex->DraWText("|", position.x - 0.26, position.y - 0.022f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
                    tex->DraWText(emptyText, position.x - 0.26, position.y - 0.022f, 1.0f, standartTextColor);
                    waitTimeLeft += Clock_De_Grande::getClock().getElapsedMCS();
                }
                else {
                    tex->DraWText(inputText + '|', position.x - 0.26, position.y - 0.022f, 1.0f, inputTextColor);
                    waitTimeLeft += Clock_De_Grande::getClock().getElapsedMCS();
                }
            }
         
            else {
                if(inputText.length() == 0)
                    tex->DraWText(emptyText, position.x - 0.26, position.y - 0.022f, 1.0f, standartTextColor);
                else 
                    tex->DraWText(inputText, position.x - 0.26, position.y - 0.022f, 1.0f, inputTextColor);

                timeLeft += Clock_De_Grande::getClock().getElapsedMCS();
                if (timeLeft >= cooldown) {
                    timeLeft = 0;
                    waitTimeLeft = 0;
                }
            }
        }
     
        else {
            if (inputText.length() == 0) {
                tex->DraWText(emptyText, position.x - 0.26, position.y - 0.022f, 1.0f, standartTextColor);
            }
            else {
                tex->DraWText(inputText, position.x - 0.26, position.y - 0.022f, 1.0f, inputTextColor);
            }
          
        }
    }
    bool handleClick(glm::vec2 mousePos) {
        getShader()->use();
        getShader()->setBool("isClick", 1);
        bool ret = false;
        DrawBlock();
        GLubyte* arr = new GLubyte[4];
        glReadPixels(mousePos.x, mousePos.y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, arr);

        if (arr[0] == 255) {
            Select();
            ret = true;
        }
        else {
            unSelect();
        }


        getShader()->setBool("isClick", 0);
        glClearColor(0.3f, 0.7f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        delete[] arr;
        return ret;
    }
    void hadleButtonPress(sf::Keyboard::Key keyCode) {
        if (!isSelected)
            return;
        if (keyCode == sf::Keyboard::BackSpace) {
            if (inputText.length() == 0)
                return;
            inputText.resize(inputText.length()-1);
             
            return;

        }
        if (inputText.length() > maxInputLength)
            return;

        if (keyCode >= 26) {
            inputText = inputText + (char)(keyCode + 22);
            winputText = winputText + (wchar_t)(keyCode + 22);
        }
           
        else {
            inputText = inputText + (char)(keyCode + 97);
            winputText = winputText + (wchar_t)(keyCode + 97);
        }
          

    }
    std::string& getEmptyText() {
        return emptyText;
    }
    std::string& getInputText() {
        return inputText;
    }
    void setInputTextColor(glm::vec3 newCol) {
        inputTextColor = newCol;
    }
    void setInputMaxLength(int newLen) {
        maxInputLength = newLen;
    }
    void setStandartLineColor(glm::vec3 newCol){
        standartLineColor = newCol;
    }
    
    std::wstring& getwInput() {
        return winputText;
    }
private:
    Text* tex;
    glm::vec3 standartLineColor = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::vec3 selectedLineColor = glm::vec3(0.351f, 0.646f, 1.0f);
    glm::vec3 standartTextColor = glm::vec3(0.88f, 0.84f, 0.8794f);
    glm::vec3 inputTextColor = glm::vec3(0.0f, 0.0f, 0.0f);
	std::string emptyText;
    std::string inputText;
    std::wstring winputText;
    int maxInputLength=10;
    bool isSelected = false;
	const int waitTime = 400000;
	float waitTimeLeft = 0;
	const int cooldown = 300000;
	float timeLeft = 0;
}; 