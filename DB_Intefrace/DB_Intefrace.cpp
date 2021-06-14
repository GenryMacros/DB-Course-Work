
#include "EventHandler.h"
int main()
{

	sf::Window win(sf::VideoMode(800, 600), "Student_Faculs");
	glViewport(0,0,800,600);
	glewInit();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	Clock_De_Grande::getClock();
	bool winIsOpen = true;
	while (winIsOpen) {
		glClearColor(0.3f, 0.7f, 0.8f, 1.0f);
		Clock_De_Grande::getClock().Restart();
		glClear(GL_COLOR_BUFFER_BIT);
		sf::Event event;
		while (win.pollEvent(event)) {
			if (event.type == sf::Event::Closed) winIsOpen = false;
			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2i mouse = sf::Mouse::getPosition(win);
				EventHandler::getEventHandler().handleMouseClick(glm::vec2(mouse.x,600-mouse.y), Scene::getScene());
			}
			if (event.type == sf::Event::KeyPressed) {
				EventHandler::getEventHandler().handleButtonPress(event.key.code, Scene::getScene());
			}
		}
		
		Scene::getScene().Draw();
		win.display();

	}
	SQLserver::getSqlServer().Disconnect();
}
