#pragma once

#include "Scene.h"
class EventHandler {
public:
	static EventHandler& getEventHandler() {
		static EventHandler handler;
		return handler;
	}
	static void handleMouseClick(glm::vec2 mousePos,Scene& sc) {
		Scene::SceneElements elems = sc.getCurrentSceneElems();
		if (!AttentionWin::getWin().isAttend()) {
			for (int i = 0; i < elems.buttons.getLength(); i++) {
				if (elems.buttons[i]->handleClick(mousePos, elems.inputs)) return;
			}
			for (int i = 0; i < elems.inputs.getLength(); i++) {
				elems.inputs[i]->handleClick(mousePos);
			}
		}
		else {
			AttentionWin::AttentionElements aElems = AttentionWin::getWin().getCurrentSceneElems();
			for (int i = 0; i < aElems.buttons.getLength(); i++) {
				if (aElems.buttons[i]->handleClick(mousePos)) return;
			}
			for (int i = 0; i < aElems.circles.getLength(); i++) {
				aElems.circles[i]->handleClick(mousePos);
			}

		}
	}
	static void handleButtonPress(sf::Keyboard::Key keyCode, Scene& sc) {
		Scene::SceneElements elems = sc.getCurrentSceneElems();

		for (int i = 0; i < elems.inputs.getLength(); i++) {
			elems.inputs[i]->hadleButtonPress(keyCode);
		}
	}
private:
	EventHandler(EventHandler& cop) = delete;
	EventHandler(const EventHandler& cop) = delete;
	EventHandler() = default;
};