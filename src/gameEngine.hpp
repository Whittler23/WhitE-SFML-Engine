#pragma once

#include <SFML/Graphics.hpp>

namespace WhitE {

class GameEngine
{
public:
	GameEngine();

	void start();

private:
	void update(const sf::Time deltaTime);
	void draw();
	void input();

private:
	sf::RenderWindow mGameWindow;

};

}