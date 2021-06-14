#pragma once
#include "SFML/Window.hpp"

class Clock_De_Grande {
	Clock_De_Grande() = default;
	Clock_De_Grande(const  Clock_De_Grande& cop) = delete;
	Clock_De_Grande(Clock_De_Grande& cop) = delete;

	sf::Clock clock;
public:
	static Clock_De_Grande& getClock() {
		static Clock_De_Grande clock;
		return clock;
	}
	void Restart() {
		clock.restart();
	}
	float getElapsedMS() {
		return clock.getElapsedTime().asMilliseconds();
	}
	float getElapsedMCS() {
		return clock.getElapsedTime().asMicroseconds();
	}
};
