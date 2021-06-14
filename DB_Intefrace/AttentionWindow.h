 #pragma once
#include "Shader.h"
#include "Button.h"
#include "Block.h"
#include "TextBlock.h"
#include "SelectionCircle.h"
#include "server.h"
#include "FullableBlock.h"

void OK(list<Input*>& inputs, std::string& reqTex);
void SendChoice(list<Input*>& inputs, std::string& reqTex);
void closeAtt(list<Input*>& inputs, std::string& reqTex);
class AttentionWin {
public:
	struct AttentionElements {
		list<Button*> buttons;
		list<Block*> blocks;
		list<TextBlock*> textBlocks;
		list<selectionCircle*> circles;
		list<FullableBlock*> fb;
	};
	static AttentionWin& getWin() {
		static AttentionWin win;
		return win;
	}
	void DrawFacultyAtt() {
		if (!ISattention)
			return;
		
        DrawBackGround();
		if (currentAT == 0) {
			for (int i = 0; i < attention.blocks.getLength(); i++) {
				attention.blocks[i]->Draw();
			}
			for (int i = 0; i < attention.buttons.getLength(); i++) {
				attention.buttons[i]->Draw();
			}
			for (int i = 0; i < attention.textBlocks.getLength(); i++) {
				attention.textBlocks[i]->Draw();
			}
		}
		else if (currentAT == 3) {
			for (int i = 0; i < subjects.blocks.getLength(); i++) {
				subjects.blocks[i]->Draw();
			}
			for (int i = 0; i < subjects.buttons.getLength(); i++) {
				subjects.buttons[i]->Draw();
			}
			for (int i = 0; i < subjects.textBlocks.getLength(); i++) {
				subjects.textBlocks[i]->Draw();
			} 
			for (int i = 0; i < subjects.fb.getLength(); i++) {
				subjects.fb[i]->Draw();
			}
		}
		else {
			for (int i = 0; i < selection.blocks.getLength(); i++) {
				selection.blocks[i]->Draw();
			}
			for (int i = 0; i < selection.buttons.getLength(); i++) {
				selection.buttons[i]->Draw();
			} 
		/*	for (int i = 0; i < selection.textBlocks.getLength(); i++) {
				selection.textBlocks[i]->Draw();
			} */
			for (int i = 0; i < selection.circles.getLength(); i++) {
				selection.circles[i]->Draw();
			}
		}

	}
	void SetShaders(Shader* Button, Shader* Block) {
		 ButtonShader = Button;
		 BlockShader = Block;
	}
	void Attention() {
		Block* attentionHolder = new Block(glm::vec3(1.6f, 0.8f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), BlockShader);
		TextBlock* textBlock1 = new TextBlock(FONT, "You haven't selected facultative yet,", 16, glm::vec3(0.9f, 0.1f, 1.0f), glm::vec3(-0.25f, 0.22f, 1.0f), BlockShader,nullptr, VAO, VBO);
		TextBlock* textBlock2 = new TextBlock(FONT, "so you'll have to do it now", 16, glm::vec3(1.0f, 0.1f, 1.0f), glm::vec3(-0.15f, 0.12f, 1.0f), BlockShader,  nullptr, VAO, VBO);
		Button* okButton = new Button(OK, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(0.01f, -0.18f, 1.0f), ButtonShader, "OK", FONT, VAO, VBO);
		attentionHolder->setColors(glm::vec3(0.9, 0.9, 0.9),glm::vec3(0,0,0));
		textBlock1->setColors(glm::vec3(0.9, 0.9, 0.9), glm::vec3(0.9, 0.9, 0.9));
		textBlock2->setColors(glm::vec3(0.9, 0.9, 0.9), glm::vec3(0.9, 0.9, 0.9));
		textBlock1->setTextColor(glm::vec3(0,0,0));
		textBlock2->setTextColor(glm::vec3(0, 0, 0));
		okButton->setColors(glm::vec3(0.949f,0.286f,0.258f),glm::vec3(0.23f,0.12f,0.098f));
		okButton->setTexPos(glm::vec2(okButton->getPosition().x-0.03, okButton->getPosition().y - 0.02));
		attention.blocks.add(attentionHolder);
		attention.textBlocks.add(textBlock1);
		attention.textBlocks.add(textBlock2);
		attention.buttons.add(okButton);
	}
	void deleteAttention() {
		attention.blocks.clear();
		attention.buttons.clear();
		attention.textBlocks.clear();
	}
	void AttentionSubject(std::string& patro,std::string& mail,std::string& phone) {
		patro = "Teacher name:" + patro;
		mail = "Mail:" + mail;
		phone = "Phone:" + phone;
		Block* attentionHolder = new Block(glm::vec3(1.2f, 1.6f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), BlockShader);
		TextBlock* textBlock1 = new TextBlock(FONT, patro.c_str(), 16, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(-0.13f, 0.22f, 1.0f), BlockShader, nullptr, VAO, VBO);
		TextBlock* textBlock2 = new TextBlock(FONT, mail.c_str(), 16, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(-0.13f, 0.12f, 1.0f), BlockShader, nullptr, VAO, VBO);
		TextBlock* textBlock3 = new TextBlock(FONT, phone.c_str(), 16, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(-0.13f, 0.02f, 1.0f), BlockShader, nullptr, VAO, VBO);
		TextBlock* textBlock4 = new TextBlock(FONT, "Current points", 16, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, -0.4f, 1.0f), BlockShader, nullptr, VAO, VBO);
		Button* closeButton = new Button(closeAtt, glm::vec3(0.09f, 0.1f, 0.2f), glm::vec3(0.441f, 0.596f, 1.0f), ButtonShader, "X", FONT, VAO, VBO);
		FullableBlock* grade = new FullableBlock(glm::vec3(0.7f, 0.1f, 1.0f), glm::vec3(0.0, -0.5f, 0), BlockShader, 0, new Text(FONT, "../ShadersTXT/text.v.txt", "../ShadersTXT/text.f.txt", 15, VAO, VBO));
		grade->SetFillencyColor(glm::vec3(0.1f, 0.8f, 0.1f));
		grade->setColors(glm::vec3(0.7f, 0.1f, 0.1f), glm::vec3(0, 0, 0));
		grade->SetTexColor(glm::vec3(0.0f, 0.0f, 0.0f));
		attentionHolder->setColors(glm::vec3(0.9, 0.9, 0.9), glm::vec3(0, 0, 0));
		textBlock1->setTextColor(glm::vec3(0, 0, 0));
		textBlock2->setTextColor(glm::vec3(0, 0, 0));
		textBlock3->setTextColor(glm::vec3(0, 0, 0));
		textBlock4->setTextColor(glm::vec3(0, 0, 0));
		closeButton->setColors(glm::vec3(0.949f, 0.286f, 0.258f), glm::vec3(0.949f, 0.286f, 0.258f));
		closeButton->setTexPos(glm::vec2(closeButton->getPosition().x-0.014f , closeButton->getPosition().y - 0.02));
		subjects.blocks.add(attentionHolder);
		subjects.textBlocks.add(textBlock1);
		subjects.textBlocks.add(textBlock2);
		subjects.textBlocks.add(textBlock3);
		subjects.textBlocks.add(textBlock4);
		subjects.buttons.add(closeButton);
		subjects.fb.add(grade);
	}
	void deleteAttentionSubject() {
		subjects.blocks.clear();
		subjects.buttons.clear();
		subjects.textBlocks.clear();
		subjects.fb.clear();
	}
	void Selection() {
		Block* attentionHolder = new Block(glm::vec3(1.6f, 0.8f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), BlockShader);
		Button* okButton = new Button(SendChoice, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(0.01f, -0.18f, 1.0f), ButtonShader, "OK", FONT, VAO, VBO);
		attentionHolder->setColors(glm::vec3(0.9, 0.9, 0.9), glm::vec3(0, 0, 0));
		okButton->setColors(glm::vec3(0.949f, 0.286f, 0.258f), glm::vec3(0.23f, 0.12f, 0.098f));
		okButton->setTexPos(glm::vec2(okButton->getPosition().x - 0.03, okButton->getPosition().y - 0.02));

		selection.blocks.add(attentionHolder);
		selection.buttons.add(okButton);
		
		
		int Ids[4];
		list<std::string> str;
		if (SQLserver::getSqlServer().GetAvaliableFacultys(ID, Ids, str)) {
			
			
		
		
			glm::vec3 firstCircle = glm::vec3(-0.08f, 0.12f, 0.0f);
			glm::vec3 scale = glm::vec3(1.0f, 1.15f, 1.0f);
			float textY = 0.12;
			AttentionWin::AttentionElements currentSc = AttentionWin::getWin().getCurrentSceneElems();
			for (int i = 0; i < str.getLength(); i++) {
				selectionCircle* circle = new selectionCircle(scale, firstCircle, ButtonShader, 0.02, 50,VAO,VBO);
				circle->SetTextPosition(-0.04, textY);
				circle->setColors(glm::vec3(0.1, 0.1, 0.1), glm::vec3(0, 0, 0));
				circle->SetTextAData(str[i],Ids[i]);
				firstCircle.y -= 0.05f;
				textY -= 0.057f; 
				selection.circles.add(circle);
			}
		}
	
		
	}
	void Attend() {
		ISattention = true;
	}
	void unAttend() {
		ISattention = false;
	}
	bool isAttend() {
		return ISattention;
	}
	void nextAT() {
		currentAT += 1;
	}
	void SetAT(int AT) {
		currentAT = AT;
	}
	void setID(int id) {
		ID = id;
	}
	int getID() {
		return ID;
	}
	AttentionElements& getCurrentSceneElems() {
		if (currentAT == 0)
			return attention;
		else if (currentAT == 1)
			return selection;
		else if (currentAT == 2)
			return attention;
		else if (currentAT = 3) {
			return subjects;
		}
	}
private:

	AttentionWin() {
		background.CreateShader(BACKGROUND_V, BACKGROUND_F);
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	}
	AttentionWin(AttentionWin& cop) = delete;
	AttentionWin(const AttentionWin& cop) = delete;

	void DrawBackGround() {
		background.use();
		background.setVec3("aColor", 0.0f, 0.0f, 0.0f);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_QUADS);
		glVertex2f(-1.0f, 1.0f);
		glVertex2f(-1.0f, -1.0f);
		glVertex2f(1.0f, -1.0f);
		glVertex2f(1.0f, 1.0f);
		glEnd();

	}
	Shader background;
	Shader* ButtonShader;
	Shader* BlockShader;
	AttentionElements attention;
	AttentionElements selection;
	AttentionElements subjects;
	int currentAT=0;
	int ID;
	GLuint VBO;
	GLuint VAO;
	bool ISattention = false;
};

void OK(list<Input*>& inputs, std::string& reqTex) {
	AttentionWin::getWin().nextAT();
	AttentionWin::getWin().Selection();
} 
void SendChoice(list<Input*>& inputs, std::string& reqTex) {
	//AttentionWin::getWin().nextAT();
	AttentionWin::AttentionElements elems = AttentionWin::getWin().getCurrentSceneElems();
	for (int i = 0; elems.circles.getLength(); i++) {
		if (elems.circles[i]->Selected()) {
			SQLserver::getSqlServer().setFacultys(elems.circles[i]->getSQLidData(), AttentionWin::getWin().getID());
			AttentionWin::getWin().unAttend();
			return;
		}
	}
}
void closeAtt(list<Input*>& inputs, std::string& reqTex) {
	AttentionWin::getWin().deleteAttentionSubject();
	AttentionWin::getWin().unAttend();

}