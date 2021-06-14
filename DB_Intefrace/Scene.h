#pragma once
#include "AttentionWindow.h"



void LogIn(list<Input*>& lst,std::string& reqTex);
void GoToFaculs(list<Input*>& lst, std::string& reqTex);
void GoToProfile(list<Input*>& lst, std::string& reqTex);
void GoToContacts(list<Input*>& lst, std::string& reqTex);
void GetTeacherInfo(list<Input*>& lst, std::string& reqTex);
void GoToSubjects(list<Input*>& lsts, std::string& reqTex);
void SubjInfoAttention(list<Input*>& lsts, std::string& reqTex);

class Scene {
public:
	struct SceneElements {
		list<Button*> buttons;
		list<Block*> blocks;
		list<TextBlock*> textBlocks;
		list<Input*> inputs;
		list<FullableBlock*> fb;
	};
	static Scene& getScene() {
		static Scene scene;
		return scene;
	}
	Scene(Scene& scene) = delete;
	Scene(const Scene& scene) = delete;

	void createScene_One() {

		Button* but1 = new Button(LogIn, glm::vec3(0.7f, 0.2f, 0.2f), glm::vec3(0.0f, -0.35f, 1.0f), ButtonShader, "Log", FONT, VAO, VBO);
		Block* block1 = new Block(glm::vec3(1.0f, 1.5f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), BlockShader);
		TextBlock* textBlock1 = new TextBlock(FONT, "Campus", 45, glm::vec3(1.0f, 0.2f, 1.0f), glm::vec3(0.0f, 0.45f, 1.0f), BlockShader, nullptr, VAO, VBO);
		Input* passwordInput = new Input(glm::vec3(0.7f, 0.2f, 0.2f), glm::vec3(0.0f, 0.05f, 1.0f), ButtonShader, "Password", FONT, VAO, VBO);
		Input* nameInput = new Input(glm::vec3(0.7f, 0.2f, 0.2f), glm::vec3(0.0f, 0.25f, 1.0f), ButtonShader, "Name", FONT, VAO, VBO);
		but1->setColors(glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.2f, 0.2f, 0.2f));
		but1->setTexPos(glm::vec2(but1->getPosition().x - 0.05f, but1->getPosition().y - 0.02f));
		but1->setTexColor(glm::vec3(1.0f, 0.83f, 0.40625f));
		block1->setColors(glm::vec3(0.92f, 0.92f, 0.92f), glm::vec3(0.92f, 0.92f, 0.92f));
		textBlock1->setColors(glm::vec3(0.92f, 0.92f, 0.92f), glm::vec3(0.92f, 0.92f, 0.92f));
		textBlock1->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		nameInput->setColors(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.5f, 0.5f, 0.5f));
		nameInput->setStandartLineColor(glm::vec3(0.5f, 0.5f, 0.5f));
		nameInput->setInputMaxLength(5);
		passwordInput->setColors(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.5f, 0.5f, 0.5f));
		passwordInput->setInputMaxLength(10);
		passwordInput->setStandartLineColor(glm::vec3(0.5f, 0.5f, 0.5f));



		scene_one.buttons.add(but1);
		scene_one.blocks.add(block1);
		scene_one.inputs.add(nameInput);
		scene_one.inputs.add(passwordInput);
		scene_one.textBlocks.add(textBlock1);
	}
	void DeleteSceneOne() {
		scene_one.blocks.clear();
		scene_one.buttons.clear();
		scene_one.inputs.clear();
		scene_one.textBlocks.clear();
	}
	void createScene_Two() {

		Block* buttonBlock = new Block(glm::vec3(0.6f, 2.2f, 1.0f), glm::vec3(-0.758f, -0.117f, 0.0f), BlockShader);
		Block* dataBlock = new Block(glm::vec3(1.92f, 2.2f, 2.0f), glm::vec3(0.23f, -0.117f, 0.0f), BlockShader);
		Button* profile = new Button(nullptr, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.68f, 1.0f), ButtonShader, "Profile", FONT, VAO, VBO);
		Button* contacts = new Button(GoToContacts, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.52f, 1.0f), ButtonShader, "Contacts", FONT, VAO, VBO);
		Button* Facultative = new Button(GoToFaculs, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.36f, 1.0f), ButtonShader, "Facultative", FONT, VAO, VBO);
		Button* Items = new Button(GoToSubjects, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.2f, 1.0f), ButtonShader, "Subjects", FONT, VAO, VBO);
		dataBlock->setColors(glm::vec3(0.3f, 0.7f, 0.8f), glm::vec3(0.3f, 0.7f, 0.8f));
		buttonBlock->setColors(glm::vec3(0.3f, 0.7f, 0.8f), glm::vec3(0.3f, 0.7f, 0.8f));
		profile->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		profile->setTexPos(glm::vec2(profile->getPosition().x - 0.2f, profile->getPosition().y - 0.02f));
		profile->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		contacts->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		contacts->setTexPos(glm::vec2(contacts->getPosition().x - 0.2f, contacts->getPosition().y - 0.02f));
		contacts->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		Facultative->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		Facultative->setTexPos(glm::vec2(Facultative->getPosition().x - 0.2f, Facultative->getPosition().y - 0.02f));
		Facultative->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		Items->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		Items->setTexPos(glm::vec2(Items->getPosition().x - 0.2f, Items->getPosition().y - 0.02f));
		Items->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		//dataBlock->setColors(glm::vec3(0.5f, 0.1f, 0.1f), glm::vec3(1.0f, 1.0f, 1.0f));

		Block* infoBlock = new Block(glm::vec3(1.6f, 1.86f, 2.0f), glm::vec3(0.17f, 0.0f, 0.0f), BlockShader);
		infoBlock->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));


		glm::vec3 decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		glm::vec3 decoPos = glm::vec3(-0.435f, 0.75f, 0.0f);
		Block* leftUPDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* leftUPDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x - 0.4 * decoScale.y, decoPos.y - 0.4 * decoScale.y, 0.0f), BlockShader);
		leftUPDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		leftUPDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		decoPos = glm::vec3(0.77f, -0.75f, 0.0f);
		Block* rightDOWNDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* rightDOWNDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x + 0.4 * decoScale.y, decoPos.y + 0.4 * decoScale.y, 0.0f), BlockShader);
		rightDOWNDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		rightDOWNDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		decoPos = glm::vec3(0.77f, 0.75f, 0.0f);
		Block* rightUPDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* rightUPDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x + 0.4 * decoScale.y, decoPos.y - 0.4 * decoScale.y, 0.0f), BlockShader);
		rightUPDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		rightUPDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		decoPos = glm::vec3(-0.435f, -0.75f, 0.0f);
		Block* leftDOWNDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* leftDOWNDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x - 0.4 * decoScale.y, decoPos.y + 0.4 * decoScale.y, 0.0f), BlockShader);
		leftDOWNDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		leftDOWNDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));


		decoScale = glm::vec3(1.0f, 0.008f, 1.0f);
		decoPos = glm::vec3(0.2f, 0.62f, 0.0f);
		Block* profLine = new Block(glm::vec3(decoScale.x, decoScale.y, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		decoPos = glm::vec3(0.2f, 0.3f, 0.0f);
		Block* mainLine = new Block(glm::vec3(decoScale.x, decoScale.y, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		decoPos = glm::vec3(0.2f, -0.33f, 0.0f);
		Block* contactLine = new Block(glm::vec3(decoScale.x, decoScale.y, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);

		contactLine->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		mainLine->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		profLine->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));



		TextBlock* Personal = new TextBlock(FONT, "Personal", 45, glm::vec3(1.0f, 0.06f, 1.0f), glm::vec3(-0.0f, 0.67f, 1.0f), BlockShader, profileText);
		std::string compStr = "Full name: " + User.getFullName();
		TextBlock* PIB = new TextBlock(FONT, compStr.c_str(), 45, glm::vec3(1.0f, 0.06f, 1.0f), glm::vec3(-0.0f, 0.55f, 1.0f), BlockShader, profileText);

		TextBlock* main = new TextBlock(FONT, "Main", 45, glm::vec3(1.0f, 0.1f, 1.0f), glm::vec3(-0.0f, 0.35f, 1.0f), BlockShader, profileText);
		compStr = "Faculty: " + User.getfacultyName();
		TextBlock* faculty = new TextBlock(FONT, compStr.c_str(), 45, glm::vec3(1.0f, 0.1f, 1.0f), glm::vec3(-0.0f, 0.23f, 1.0f), BlockShader, profileText);
		compStr = "Speciality: " + User.getspecialityName();
		TextBlock* spec = new TextBlock(FONT, compStr.c_str(), 45, glm::vec3(1.0f, 0.1f, 1.0f), glm::vec3(-0.0f, 0.13f, 1.0f), BlockShader, profileText);
		compStr = "Group: " + User.getGroup();
		TextBlock* GroupName = new TextBlock(FONT, compStr.c_str(), 45, glm::vec3(1.0f, 0.1f, 1.0f), glm::vec3(-0.0f, 0.03f, 1.0f), BlockShader, profileText);

		compStr = "Course: ";
		compStr += User.getCourse();

		TextBlock* course = new TextBlock(FONT, compStr.c_str(), 45, glm::vec3(1.0f, 0.1f, 1.0f), glm::vec3(-0.0f, -0.07f, 1.0f), BlockShader, profileText);

		TextBlock* scontacts = new TextBlock(FONT, "Contacts", 45, glm::vec3(1.0f, 0.1f, 1.0f), glm::vec3(-0.0f, -0.28f, 1.0f), BlockShader, profileText);
		compStr = "Mail: " + User.getMail();
		TextBlock* mail = new TextBlock(FONT, compStr.c_str(), 45, glm::vec3(1.0f, 0.1f, 1.0f), glm::vec3(-0.0f, -0.38f, 1.0f), BlockShader, profileText);
		compStr = "Phone: " + User.getPhone();
		TextBlock* phone = new TextBlock(FONT, compStr.c_str(), 45, glm::vec3(1.0f, 0.1f, 1.0f), glm::vec3(-0.0f, -0.48f, 1.0f), BlockShader, profileText);

		faculty->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		spec->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		GroupName->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		course->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		mail->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		Personal->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		main->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		scontacts->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		phone->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));

		PIB->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		PIB->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));
		faculty->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));
		spec->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));
		GroupName->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));
		course->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));
		mail->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));
		phone->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));

		Personal->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));
		main->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));
		scontacts->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));

		scene_two.blocks.add(buttonBlock);
		scene_two.blocks.add(dataBlock);
		scene_two.blocks.add(infoBlock);
		scene_two.blocks.add(leftUPDecoX);
		scene_two.blocks.add(leftUPDecoY);
		scene_two.blocks.add(rightDOWNDecoX);
		scene_two.blocks.add(rightDOWNDecoY);
		scene_two.blocks.add(rightUPDecoX);
		scene_two.blocks.add(rightUPDecoY);
		scene_two.blocks.add(leftDOWNDecoX);
		scene_two.blocks.add(leftDOWNDecoY);
		scene_two.blocks.add(contactLine);
		scene_two.blocks.add(mainLine);
		scene_two.blocks.add(profLine);
		scene_two.buttons.add(profile);
		scene_two.buttons.add(contacts);
		scene_two.buttons.add(Facultative);
		scene_two.buttons.add(Items);
		scene_two.textBlocks.add(PIB);
		scene_two.textBlocks.add(faculty);
		scene_two.textBlocks.add(spec);
		scene_two.textBlocks.add(GroupName);
		scene_two.textBlocks.add(course);
		scene_two.textBlocks.add(mail);
		scene_two.textBlocks.add(Personal);
		scene_two.textBlocks.add(main);
		scene_two.textBlocks.add(scontacts);
		scene_two.textBlocks.add(phone);
	}
	void DeleteSceneTwo() {
		scene_two.blocks.clear();
		scene_two.buttons.clear();
		scene_two.inputs.clear();
		scene_two.textBlocks.clear();

	}
	void CreateSceneContacts() {
		Block* buttonBlock = new Block(glm::vec3(0.6f, 2.2f, 1.0f), glm::vec3(-0.758f, -0.117f, 0.0f), BlockShader);
		Block* dataBlock = new Block(glm::vec3(1.92f, 2.2f, 2.0f), glm::vec3(0.23f, -0.117f, 0.0f), BlockShader);
		Button* profile = new Button(GoToProfile, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.68f, 1.0f), ButtonShader, "Profile", FONT, VAO, VBO);
		Button* contacts = new Button(nullptr, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.52f, 1.0f), ButtonShader, "Contacts", FONT, VAO, VBO);
		Button* Facultative = new Button(GoToFaculs, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.36f, 1.0f), ButtonShader, "Facultative", FONT, VAO, VBO);
		Button* Items = new Button(GoToSubjects, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.2f, 1.0f), ButtonShader, "Subjects", FONT, VAO, VBO);
		dataBlock->setColors(glm::vec3(0.3f, 0.7f, 0.8f), glm::vec3(0.3f, 0.7f, 0.8f));
		buttonBlock->setColors(glm::vec3(0.3f, 0.7f, 0.8f), glm::vec3(0.3f, 0.7f, 0.8f));
		profile->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		profile->setTexPos(glm::vec2(profile->getPosition().x - 0.2f, profile->getPosition().y - 0.02f));
		profile->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		contacts->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		contacts->setTexPos(glm::vec2(contacts->getPosition().x - 0.2f, contacts->getPosition().y - 0.02f));
		contacts->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		Facultative->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		Facultative->setTexPos(glm::vec2(Facultative->getPosition().x - 0.2f, Facultative->getPosition().y - 0.02f));
		Facultative->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		Items->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		Items->setTexPos(glm::vec2(Items->getPosition().x - 0.2f, Items->getPosition().y - 0.02f));
		Items->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		//dataBlock->setColors(glm::vec3(0.5f, 0.1f, 0.1f), glm::vec3(1.0f, 1.0f, 1.0f));

		Block* infoBlock = new Block(glm::vec3(1.6f, 1.86f, 2.0f), glm::vec3(0.17f, 0.0f, 0.0f), BlockShader);
		infoBlock->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));


		glm::vec3 decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		glm::vec3 decoPos = glm::vec3(-0.435f, 0.75f, 0.0f);
		Block* leftUPDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* leftUPDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x - 0.4 * decoScale.y, decoPos.y - 0.4 * decoScale.y, 0.0f), BlockShader);
		leftUPDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		leftUPDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		decoPos = glm::vec3(0.77f, -0.75f, 0.0f);
		Block* rightDOWNDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* rightDOWNDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x + 0.4 * decoScale.y, decoPos.y + 0.4 * decoScale.y, 0.0f), BlockShader);
		rightDOWNDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		rightDOWNDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		decoPos = glm::vec3(0.77f, 0.75f, 0.0f);
		Block* rightUPDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* rightUPDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x + 0.4 * decoScale.y, decoPos.y - 0.4 * decoScale.y, 0.0f), BlockShader);
		rightUPDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		rightUPDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		decoPos = glm::vec3(-0.435f, -0.75f, 0.0f);
		Block* leftDOWNDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* leftDOWNDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x - 0.4 * decoScale.y, decoPos.y + 0.4 * decoScale.y, 0.0f), BlockShader);
		leftDOWNDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		leftDOWNDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		scene_Contacts.blocks.add(buttonBlock);
		scene_Contacts.blocks.add(dataBlock);
		scene_Contacts.blocks.add(infoBlock);
		scene_Contacts.blocks.add(leftUPDecoX);
		scene_Contacts.blocks.add(leftUPDecoY);
		scene_Contacts.blocks.add(rightDOWNDecoX);
		scene_Contacts.blocks.add(rightDOWNDecoY);
		scene_Contacts.blocks.add(rightUPDecoX);
		scene_Contacts.blocks.add(rightUPDecoY);
		scene_Contacts.blocks.add(leftDOWNDecoX);
		scene_Contacts.blocks.add(leftDOWNDecoY);
		scene_Contacts.buttons.add(profile);
		scene_Contacts.buttons.add(contacts);
		scene_Contacts.buttons.add(Facultative);
		scene_Contacts.buttons.add(Items);
		CreateSearchInputContacts();
	}
	void CreateSearchInputContacts() {
		Input* subjInput = new Input(glm::vec3(0.7f, 0.2f, 0.2f), glm::vec3(0.17f, 0.5f, 1.0f), ButtonShader, "Subject name", FONT, VAO, VBO);
		subjInput->setInputMaxLength(10);
		Button* search = new Button(GetTeacherInfo, glm::vec3(0.6f, 0.15f, 0.2f), glm::vec3(0.17f, 0.3f, 1.0f), ButtonShader, "Search", FONT, VAO, VBO);
		TextBlock* fullName = new TextBlock(FONT, "Full name:", 45, glm::vec3(1.0f, 0.2f, 1.0f), glm::vec3(-0.06f, 0.05f, 1.0f), BlockShader, profileText);
		TextBlock* phone = new TextBlock(FONT, "Phone:", 45, glm::vec3(1.0f, 0.2f, 1.0f), glm::vec3(-0.06f, -0.05f, 1.0f), BlockShader, profileText);
		TextBlock* mail = new TextBlock(FONT, "Mail:", 45, glm::vec3(1.0f, 0.2f, 1.0f), glm::vec3(-0.06f, -0.15f, 1.0f), BlockShader, profileText);
		fullName->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		fullName->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));
		phone->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		phone->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));
		mail->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		mail->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));

		search->setTexPos(glm::vec2(search->getPosition().x - 0.09f, search->getPosition().y - 0.026f));
		search->setColors(glm::vec3(0.2f, 0.5f, 0.6f), glm::vec3(0, 0, 0));
		subjInput->setColors(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.5f, 0.5f, 0.5f));
		subjInput->setStandartLineColor(glm::vec3(0.5f, 0.5f, 0.5f));


		scene_Contacts.inputs.add(subjInput);
		scene_Contacts.buttons.add(search);
		scene_Contacts.textBlocks.add(fullName);
		scene_Contacts.textBlocks.add(phone);
		scene_Contacts.textBlocks.add(mail);
	}
	void DeleteContacts() {
		scene_Contacts.blocks.clear();
		scene_Contacts.buttons.clear();
		scene_Contacts.inputs.clear();
		scene_Contacts.textBlocks.clear();
	}
	void CreateSceneFacul() {

		Block* buttonBlock = new Block(glm::vec3(0.6f, 2.2f, 1.0f), glm::vec3(-0.758f, -0.117f, 0.0f), BlockShader);
		Block* dataBlock = new Block(glm::vec3(1.92f, 2.2f, 2.0f), glm::vec3(0.23f, -0.117f, 0.0f), BlockShader);
		Button* profile = new Button(GoToProfile, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.68f, 1.0f), ButtonShader, "Profile", FONT, VAO, VBO);
		Button* contacts = new Button(GoToContacts, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.52f, 1.0f), ButtonShader, "Contacts", FONT, VAO, VBO);
		Button* Facultative = new Button(nullptr, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.36f, 1.0f), ButtonShader, "Facultative", FONT, VAO, VBO);
		Button* Items = new Button(GoToSubjects, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.2f, 1.0f), ButtonShader, "Subjects", FONT, VAO, VBO);
		dataBlock->setColors(glm::vec3(0.3f, 0.7f, 0.8f), glm::vec3(0.3f, 0.7f, 0.8f));
		buttonBlock->setColors(glm::vec3(0.3f, 0.7f, 0.8f), glm::vec3(0.3f, 0.7f, 0.8f));
		profile->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		profile->setTexPos(glm::vec2(profile->getPosition().x - 0.2f, profile->getPosition().y - 0.02f));
		profile->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		contacts->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		contacts->setTexPos(glm::vec2(contacts->getPosition().x - 0.2f, contacts->getPosition().y - 0.02f));
		contacts->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		Facultative->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		Facultative->setTexPos(glm::vec2(Facultative->getPosition().x - 0.2f, Facultative->getPosition().y - 0.02f));
		Facultative->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		Items->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		Items->setTexPos(glm::vec2(Items->getPosition().x - 0.2f, Items->getPosition().y - 0.02f));
		Items->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		//dataBlock->setColors(glm::vec3(0.5f, 0.1f, 0.1f), glm::vec3(1.0f, 1.0f, 1.0f));

		Block* infoBlock = new Block(glm::vec3(1.6f, 1.86f, 2.0f), glm::vec3(0.17f, 0.0f, 0.0f), BlockShader);
		infoBlock->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));


		glm::vec3 decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		glm::vec3 decoPos = glm::vec3(-0.435f, 0.75f, 0.0f);
		Block* leftUPDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* leftUPDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x - 0.4 * decoScale.y, decoPos.y - 0.4 * decoScale.y, 0.0f), BlockShader);
		leftUPDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		leftUPDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		decoPos = glm::vec3(0.77f, -0.75f, 0.0f);
		Block* rightDOWNDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* rightDOWNDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x + 0.4 * decoScale.y, decoPos.y + 0.4 * decoScale.y, 0.0f), BlockShader);
		rightDOWNDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		rightDOWNDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		decoPos = glm::vec3(0.77f, 0.75f, 0.0f);
		Block* rightUPDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* rightUPDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x + 0.4 * decoScale.y, decoPos.y - 0.4 * decoScale.y, 0.0f), BlockShader);
		rightUPDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		rightUPDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		decoPos = glm::vec3(-0.435f, -0.75f, 0.0f);
		Block* leftDOWNDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* leftDOWNDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x - 0.4 * decoScale.y, decoPos.y + 0.4 * decoScale.y, 0.0f), BlockShader);
		leftDOWNDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		leftDOWNDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		scene_facul.blocks.add(buttonBlock);
		scene_facul.blocks.add(dataBlock);
		scene_facul.blocks.add(infoBlock);
		scene_facul.blocks.add(leftUPDecoX);
		scene_facul.blocks.add(leftUPDecoY);
		scene_facul.blocks.add(rightDOWNDecoX);
		scene_facul.blocks.add(rightDOWNDecoY);
		scene_facul.blocks.add(rightUPDecoX);
		scene_facul.blocks.add(rightUPDecoY);
		scene_facul.blocks.add(leftDOWNDecoX);
		scene_facul.blocks.add(leftDOWNDecoY);
		scene_facul.buttons.add(profile);
		scene_facul.buttons.add(contacts);
		scene_facul.buttons.add(Facultative);
		scene_facul.buttons.add(Items);
	}
	void CreateStudentFacultyInfo() {

		profileText = new Text(FONT, "../ShadersTXT/text.v.txt", "../ShadersTXT/text.f.txt", 15, VBO, VAO);

		//TextBlock* Personal = new TextBlock(FONT, "Personal", 45, glm::vec3(1.0f, 0.06f, 1.0f), glm::vec3(-0.0f, 0.67f, 1.0f), BlockShader, profileText);
		std::string compStr = "Subject name: " + User.getFacultativeName();
		TextBlock* subj = new TextBlock(FONT, compStr.c_str(), 45, glm::vec3(1.0f, 0.06f, 1.0f), glm::vec3(-0.0f, 0.5f, 1.0f), BlockShader, profileText);


		//TextBlock* main = new TextBlock(FONT, "Main", 45, glm::vec3(1.0f, 0.1f, 1.0f), glm::vec3(-0.0f, 0.35f, 1.0f), BlockShader, profileText);
		compStr = "Total Hours: ";
		compStr += std::to_string(User.getFacultativeHours());
		TextBlock* hours = new TextBlock(FONT, compStr.c_str(), 45, glm::vec3(1.0f, 0.1f, 1.0f), glm::vec3(-0.0f, 0.4f, 1.0f), BlockShader, profileText);

		hours->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		subj->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));

		hours->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));
		subj->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));

		FullableBlock* grade = new FullableBlock(glm::vec3(1.2f, 0.1f, 1.0f), glm::vec3(0.15f, 0, 0), BlockShader, User.getFacultativeGrade(), profileText);
		grade->SetFillencyColor(glm::vec3(0.1f, 0.8f, 0.1f));
		grade->setColors(glm::vec3(0.7f, 0.1f, 0.1f), glm::vec3(0, 0, 0));
		grade->SetTexColor(glm::vec3(0.0f, 0.0f, 0.0f));
		TextBlock* gradeText = new TextBlock(FONT, "Grade", 50, glm::vec3(1.0f, 0.06f, 1.0f), glm::vec3(-0.0f, 0.55f, 1.0f), BlockShader, profileText);

		gradeText->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
		gradeText->setPosition(glm::vec3(0.293f, 0.1f, 0));
		gradeText->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));

		scene_facul.textBlocks.add(subj);
		scene_facul.textBlocks.add(hours);
		scene_facul.textBlocks.add(gradeText);
		scene_facul.fb.add(grade);

	}
	void DeleteSceneFaculs() {
		scene_facul.blocks.clear();
		scene_facul.buttons.clear();
		scene_facul.inputs.clear();
		scene_facul.textBlocks.clear();
		scene_facul.fb.clear();
	}
	void CreateSceneSubjects() {
		Block* buttonBlock = new Block(glm::vec3(0.6f, 2.2f, 1.0f), glm::vec3(-0.758f, -0.117f, 0.0f), BlockShader);
		Block* dataBlock = new Block(glm::vec3(1.92f, 2.2f, 2.0f), glm::vec3(0.23f, -0.117f, 0.0f), BlockShader);
		Button* profile = new Button(GoToProfile, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.68f, 1.0f), ButtonShader, "Profile", FONT, VAO, VBO);
		Button* contacts = new Button(GoToContacts, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.52f, 1.0f), ButtonShader, "Contacts", FONT, VAO, VBO);
		Button* Facultative = new Button(GoToFaculs, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.36f, 1.0f), ButtonShader, "Facultative", FONT, VAO, VBO);
		Button* Items = new Button(nullptr, glm::vec3(0.6f, 0.2f, 0.2f), glm::vec3(-0.78f, 0.2f, 1.0f), ButtonShader, "Subjects", FONT, VAO, VBO);
		dataBlock->setColors(glm::vec3(0.3f, 0.7f, 0.8f), glm::vec3(0.3f, 0.7f, 0.8f));
		buttonBlock->setColors(glm::vec3(0.3f, 0.7f, 0.8f), glm::vec3(0.3f, 0.7f, 0.8f));
		profile->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		profile->setTexPos(glm::vec2(profile->getPosition().x - 0.2f, profile->getPosition().y - 0.02f));
		profile->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		contacts->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		contacts->setTexPos(glm::vec2(contacts->getPosition().x - 0.2f, contacts->getPosition().y - 0.02f));
		contacts->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		Facultative->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		Facultative->setTexPos(glm::vec2(Facultative->getPosition().x - 0.2f, Facultative->getPosition().y - 0.02f));
		Facultative->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		Items->setColors(glm::vec3(0.3f, 0.6f, 0.7f), glm::vec3(0.3f, 0.7f, 0.8f));
		Items->setTexPos(glm::vec2(Items->getPosition().x - 0.2f, Items->getPosition().y - 0.02f));
		Items->setTexColor(glm::vec3(0.179f, 0.2f, 0.2614f));
		//dataBlock->setColors(glm::vec3(0.5f, 0.1f, 0.1f), glm::vec3(1.0f, 1.0f, 1.0f));

		Block* infoBlock = new Block(glm::vec3(1.6f, 1.86f, 2.0f), glm::vec3(0.17f, 0.0f, 0.0f), BlockShader);
		infoBlock->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));


		glm::vec3 decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		glm::vec3 decoPos = glm::vec3(-0.435f, 0.75f, 0.0f);
		Block* leftUPDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* leftUPDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x - 0.4 * decoScale.y, decoPos.y - 0.4 * decoScale.y, 0.0f), BlockShader);
		leftUPDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		leftUPDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		decoPos = glm::vec3(0.77f, -0.75f, 0.0f);
		Block* rightDOWNDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* rightDOWNDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x + 0.4 * decoScale.y, decoPos.y + 0.4 * decoScale.y, 0.0f), BlockShader);
		rightDOWNDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		rightDOWNDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		decoPos = glm::vec3(0.77f, 0.75f, 0.0f);
		Block* rightUPDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* rightUPDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x + 0.4 * decoScale.y, decoPos.y - 0.4 * decoScale.y, 0.0f), BlockShader);
		rightUPDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		rightUPDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
		decoPos = glm::vec3(-0.435f, -0.75f, 0.0f);
		Block* leftDOWNDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(decoPos.x, decoPos.y, 0.0f), BlockShader);
		Block* leftDOWNDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(decoPos.x - 0.4 * decoScale.y, decoPos.y + 0.4 * decoScale.y, 0.0f), BlockShader);
		leftDOWNDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		leftDOWNDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

		scene_Subjects.blocks.add(buttonBlock);
		scene_Subjects.blocks.add(dataBlock);
		scene_Subjects.blocks.add(infoBlock);
		scene_Subjects.blocks.add(leftUPDecoX);
		scene_Subjects.blocks.add(leftUPDecoY);
		scene_Subjects.blocks.add(rightDOWNDecoX);
		scene_Subjects.blocks.add(rightDOWNDecoY);
		scene_Subjects.blocks.add(rightUPDecoX);
		scene_Subjects.blocks.add(rightUPDecoY);
		scene_Subjects.blocks.add(leftDOWNDecoX);
		scene_Subjects.blocks.add(leftDOWNDecoY);
		scene_Subjects.buttons.add(profile);
		scene_Subjects.buttons.add(contacts);
		scene_Subjects.buttons.add(Facultative);
		scene_Subjects.buttons.add(Items);
		CreateSceneSubjectSpec();
	}
	void CreateSceneSubjectSpec() {
		list<int> grades;
		list<std::string> subjects;
		SQLserver::getSqlServer().GetStudentSubjects(User.getID(),subjects,grades);
		glm::vec3 pos =glm::vec3(0.0f, 0.6f, 1.0f);
		glm::vec3 decoScale;
		float decoYmodifier = 0.02f;
		for (int i = 0; i < grades.getLength(); i++) {
			
			decoScale = glm::vec3(0.008f, 0.1f, 1.0f);
			TextBlock* subj = new TextBlock(FONT, subjects[i].c_str(), 45, glm::vec3(0.000f, 0.000f, 1.0f), pos, BlockShader, profileText);
			FullableBlock* grade = new FullableBlock(glm::vec3(0.5f, 0.1f, 1.0f), glm::vec3(pos.x+0.4f, pos.y, 0), BlockShader, grades[i], profileText);
			Button* profile = new Button(SubjInfoAttention, glm::vec3(1.09f, 0.135f, 0.2f), glm::vec3(pos.x+0.2f, pos.y, 1.0f), ButtonShader, "", FONT, VAO, VBO);
			profile->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));
			profile->setReqTex(subjects[i]);
			Block* decoLine = new Block(glm::vec3(1.4f, decoScale.x, 1.0f), glm::vec3(0.17f, pos.y-0.06f, 0.0f), BlockShader);
			
			Block* leftUPDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(pos.x-0.4* 0.5f, pos.y+ 0.1f*0.4f + decoYmodifier, 0.0f), BlockShader);
			Block* leftUPDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3((pos.x - 0.4 * 0.5f) - 0.4 * decoScale.y, (pos.y + 0.1f * 0.4f + decoYmodifier) - 0.4 * decoScale.y, 0.0f), BlockShader);
			leftUPDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
			leftUPDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

			Block* leftDOWNDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(pos.x - 0.4 * 0.5f, pos.y - 0.1f * 0.4f - decoYmodifier, 0.0f), BlockShader);
			Block* leftDOWNDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(pos.x - 0.4 * 0.5f - 0.4 * decoScale.y, pos.y - 0.1f * 0.4f- decoYmodifier + 0.4 * decoScale.y, 0.0f), BlockShader);
			leftDOWNDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
			leftDOWNDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

			Block* rightDOWNDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(pos.x + 0.4 * 0.5f + 0.8f * 0.5f, pos.y - 0.1f * 0.4f- decoYmodifier, 0.0f), BlockShader);
			Block* rightDOWNDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(pos.x + 0.4 * 0.5f + 0.8f * 0.5f + 0.4 * decoScale.y, pos.y - 0.1f * 0.4f- decoYmodifier + 0.4 * decoScale.y, 0.0f), BlockShader);
			rightDOWNDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
			rightDOWNDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

			Block* rightUPDecoX = new Block(glm::vec3(decoScale.y, decoScale.x, 1.0f), glm::vec3(pos.x + 0.4 * 0.5f + 0.8f * 0.5f, pos.y + decoYmodifier+ 0.1f * 0.4f, 0.0f), BlockShader);
			Block* rightUPDecoY = new Block(glm::vec3(decoScale.x - 0.002f, decoScale.y, 1.0f), glm::vec3(pos.x + 0.4 * 0.5f + 0.8f * 0.5f + 0.4 * decoScale.y, pos.y + 0.1f * 0.4f+ decoYmodifier - 0.4 * decoScale.y, 0.0f), BlockShader);
			rightUPDecoX->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
			rightUPDecoY->setColors(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));

			grade->SetFillencyColor(glm::vec3(0.1f, 0.8f, 0.1f));
			grade->setColors(glm::vec3(0.7f, 0.1f, 0.1f), glm::vec3(0, 0, 0));
			grade->SetTexColor(glm::vec3(0.0f, 0.0f, 0.0f));

			subj->setTextColor(glm::vec3(0.0f, 0.0f, 0.0f));
			subj->setColors(glm::vec3(0.7f, 0.8f, 0.9f), glm::vec3(0.7f, 0.8f, 0.9f));

			scene_Subjects.textBlocks.add(subj);
			scene_Subjects.fb.add(grade);
			scene_Subjects.buttons.add(profile);
			scene_Subjects.blocks.add(leftUPDecoX);
			scene_Subjects.blocks.add(leftUPDecoY);
			scene_Subjects.blocks.add(rightDOWNDecoX);
			scene_Subjects.blocks.add(rightDOWNDecoY);
			scene_Subjects.blocks.add(rightUPDecoX);
			scene_Subjects.blocks.add(rightUPDecoY);
			scene_Subjects.blocks.add(leftDOWNDecoX);
			scene_Subjects.blocks.add(leftDOWNDecoY);
			
			pos.y -= 0.15f;
		}
		
	}
	void DeleteSubjectsScene() {
		scene_Subjects.blocks.clear();
		scene_Subjects.buttons.clear();
		scene_Subjects.inputs.clear();
		scene_Subjects.textBlocks.clear();
		scene_Subjects.fb.clear();
	}
	void Draw() {
		if(currentScene==0){
			for (int i = 0; i < scene_one.blocks.getLength(); i++) {
				scene_one.blocks[i]->Draw();
			}
			for (int i = 0; i < scene_one.buttons.getLength(); i++) {
				scene_one.buttons[i]->Draw();
			}
			for (int i = 0; i < scene_one.inputs.getLength(); i++) {
				scene_one.inputs[i]->Draw();
			}
			for (int i = 0; i < scene_one.textBlocks.getLength(); i++) {
				scene_one.textBlocks[i]->Draw();
			}
			ErrorsSceneOneText();
		}
		else if (currentScene == 1) {

			for (int i = 0; i < scene_two.blocks.getLength(); i++) {
				scene_two.blocks[i]->Draw();
			}
			for (int i = 0; i < scene_two.buttons.getLength(); i++) {
				scene_two.buttons[i]->Draw();
			}
			for (int i = 0; i < scene_two.inputs.getLength(); i++) {
				scene_two.inputs[i]->Draw();
			}
			for (int i = 0; i < scene_two.textBlocks.getLength(); i++) {
				scene_two.textBlocks[i]->Draw();
			}
			AttentionWin::getWin().DrawFacultyAtt();
		}
		else if (currentScene == 2) {
			for (int i = 0; i < scene_facul.blocks.getLength(); i++) {
				scene_facul.blocks[i]->Draw();
			}
			for (int i = 0; i < scene_facul.buttons.getLength(); i++) {
				scene_facul.buttons[i]->Draw();
			}
			for (int i = 0; i < scene_facul.inputs.getLength(); i++) {
				scene_facul.inputs[i]->Draw();
			}
			for (int i = 0; i < scene_facul.textBlocks.getLength(); i++) {
				scene_facul.textBlocks[i]->Draw();
			}
			for (int i = 0; i < scene_facul.fb.getLength(); i++) {
				scene_facul.fb[i]->Draw();
			}
				AttentionWin::getWin().DrawFacultyAtt();
		}
		else if (currentScene == 3) {
			for (int i = 0; i < scene_Contacts.blocks.getLength(); i++) {
				scene_Contacts.blocks[i]->Draw();
			}
			for (int i = 0; i < scene_Contacts.buttons.getLength(); i++) {
				scene_Contacts.buttons[i]->Draw();
			}
			for (int i = 0; i < scene_Contacts.inputs.getLength(); i++) {
				scene_Contacts.inputs[i]->Draw();
			}
			for (int i = 0; i < scene_Contacts.textBlocks.getLength(); i++) {
				scene_Contacts.textBlocks[i]->Draw();
			}
			for (int i = 0; i < scene_Contacts.fb.getLength(); i++) {
				scene_Contacts.fb[i]->Draw();
			}
			//AttentionWin::getWin().DrawFacultyAtt();
		}
		else if (currentScene==4) {
			for (int i = 0; i < scene_Subjects.blocks.getLength(); i++) {
				scene_Subjects.blocks[i]->Draw();
			}
			for (int i = 0; i < scene_Subjects.buttons.getLength(); i++) {
				scene_Subjects.buttons[i]->Draw();
			}
			for (int i = 0; i < scene_Subjects.inputs.getLength(); i++) {
				scene_Subjects.inputs[i]->Draw();
			}
			for (int i = 0; i < scene_Subjects.textBlocks.getLength(); i++) {
				scene_Subjects.textBlocks[i]->Draw();
			}
			for (int i = 0; i < scene_Subjects.fb.getLength(); i++) {
				scene_Subjects.fb[i]->Draw();
			}
			AttentionWin::getWin().DrawFacultyAtt();
		}
	
	}
	void SetScene(int scene) {
		currentScene = scene;
	
	}
	SceneElements& getCurrentSceneElems() {
		if (currentScene == 0)
			return scene_one;
		else if (currentScene == 1)
			return scene_two;
		else if (currentScene == 2)
			return scene_facul;
		else if (currentScene == 3)
			return scene_Contacts;
		else if (currentScene == 4)
			return scene_Subjects;
	}
	void DeleteCurrentScene() {
		if (currentScene == 0)
			DeleteSceneOne();
		else if (currentScene == 1)
			DeleteSceneTwo();
		else if (currentScene == 2)
			DeleteSceneFaculs();
		else if (currentScene == 3)
			DeleteContacts();
		else if (currentScene == 4)
			DeleteSubjectsScene();
	}
	UserInfo& getUser() {
		return User;
	}
	void ErrorsSceneOneText() {
		if(error)errorText->DraWText("wrong login/password",-0.28,-0.1,1.0f,glm::vec3(0.7f,0.0f,0.0f));
	}

	void Error() {
		error = true;
	}
	bool getError() {
		return error;
	}
	void setAttention() {
		attention = true;
	}
	bool isAttention() {
		return attention;
	}
	
	Shader* BlockShader;
	Shader* ButtonShader;
private:
	Scene() {
		SQLserver::getSqlServer().Connect();
		ButtonShader = new Shader;
		BlockShader= new Shader;
		ButtonShader->CreateShader(BUTTON_vSHADER_PATH, BUTTON_fSHADER_PATH);
		BlockShader->CreateShader(STANDART_vSHADER_PATH, STANDART_fSHADER_PATH);
		
		//createScene_Two();
		
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
		
		errorText = new Text(FONT, "../ShadersTXT/text.v.txt", "../ShadersTXT/text.f.txt", 13, VAO, VBO);
		profileText = new Text(FONT, "../ShadersTXT/text.v.txt", "../ShadersTXT/text.f.txt", 15, VAO, VBO);
		createScene_One();
	}
	int currentScene=0;
	bool attention = false;
	bool error = false;
	SceneElements scene_one;
	SceneElements scene_two;
	SceneElements scene_facul;
	SceneElements scene_Contacts;
	SceneElements scene_Subjects;
	UserInfo User;
	Text* errorText;
	Text* profileText;
	GLuint VAO;
	GLuint VBO;
	
};


void LogIn(list<Input*>& lst, std::string& reqTex) {
	std::wstring login;
	std::wstring pass;
	for (int i = 0; i < lst.getLength(); i++) {
	
		if (lst[i]->getEmptyText() == " Password") {
			std::string str = lst[i]->getInputText();

			for (int i = 0; i < str.length(); i++) {
				pass += (wchar_t)str[i];
			}
		}
		else {
			std::string str = lst[i]->getInputText();

			for (int i = 0; i < str.length(); i++) {
				login += (wchar_t)str[i];
			}
		}
	}
	if (!login.length() || !pass.length())
		return;

	if (SQLserver::getSqlServer().LogIn(login.c_str(), pass.c_str(),Scene::getScene().getUser())) {
		Scene::getScene().DeleteCurrentScene();
		Scene::getScene().SetScene(1);
		Scene::getScene().createScene_Two();
	}
	else {
		Scene::getScene().Error();
	}

}
void GoToFaculs(list<Input*>& lst, std::string& reqTex) {
	
	if (Scene::getScene().getUser().isFaculGet()) {
		Scene::getScene().DeleteCurrentScene();
		Scene::getScene().SetScene(2);
		Scene::getScene().CreateSceneFacul();
		Scene::getScene().CreateStudentFacultyInfo();
		return;
	}
	
	int ID = Scene::getScene().getUser().getID();
	if (!SQLserver::getSqlServer().CheckFaculs(ID)) {
		Scene::getScene().setAttention();
		AttentionWin::getWin().setID(Scene::getScene().getUser().getID());
		AttentionWin::getWin().SetShaders(Scene::getScene().ButtonShader, Scene::getScene().BlockShader);
		AttentionWin::getWin().Attend();
		AttentionWin::getWin().Attention();
	}
	else {
		if (SQLserver::getSqlServer().GetStudentFaculty(Scene::getScene().getUser())) {
			Scene::getScene().CreateStudentFacultyInfo();
		}
	}
}
void GoToProfile(list<Input*>& lst, std::string& reqTex) {
	Scene::getScene().DeleteCurrentScene();
	Scene::getScene().SetScene(1);
	Scene::getScene().createScene_Two();
}
void GoToContacts(list<Input*>& lst, std::string& reqTex) {
	Scene::getScene().DeleteCurrentScene();
	Scene::getScene().SetScene(3);
	Scene::getScene().CreateSceneContacts();
}
void GetTeacherInfo(list<Input*>& lst, std::string& reqTex) {
	std::string FullName;
	std::string phone;
	std::string mail;
	std::string subj;
	std::string inputText = lst[0]->getInputText();
	subj += char(inputText[0] - 32);
	subj += char(inputText[1] - 32);
	for (int i = 2; i < inputText.length(); i++) {
		subj += inputText[i];
	}
	if (SQLserver::getSqlServer().FindTeacherContacts(Scene::getScene().getUser().getID(), subj, FullName, phone, mail)) {
		FullName = "Full name: " + FullName;
		Scene::getScene().getCurrentSceneElems().textBlocks[0]->setText(FullName);
		phone = "Phone: " + phone;
		Scene::getScene().getCurrentSceneElems().textBlocks[1]->setText(phone);
		mail = "Mail: " + mail;
		Scene::getScene().getCurrentSceneElems().textBlocks[2]->setText(mail);
	}
	else {

	}
}
void GoToSubjects(list<Input*>& lsts, std::string& reqTex) {
	Scene::getScene().DeleteCurrentScene();
	Scene::getScene().SetScene(4);
	Scene::getScene().CreateSceneSubjects();
}
void ShowSubjInfo(list<Input*>& lsts, std::string& reqTex) {
	Scene::getScene().DeleteCurrentScene();
	Scene::getScene().SetScene(4);
	Scene::getScene().CreateSceneSubjects();
}
void SubjInfoAttention(list<Input*>& lsts,std::string& reqTex) {
	Scene::getScene().setAttention();
	AttentionWin::getWin().SetShaders(Scene::getScene().ButtonShader, Scene::getScene().BlockShader);
	AttentionWin::getWin().Attend();
	AttentionWin::getWin().SetAT(3);
	std::string patro;
	std::string phone;
	std::string mail;
	SQLserver::getSqlServer().GetStudentSubjectData(Scene::getScene().getUser().getID(),reqTex,patro,mail,phone );

	AttentionWin::getWin().AttentionSubject(patro,mail,phone);
}