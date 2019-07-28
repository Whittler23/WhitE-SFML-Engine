#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace WhitE {

class GameEngine
{
public:
	GameEngine();

	void start();

private:
	sf::RenderWindow mGameWindow;

};

}