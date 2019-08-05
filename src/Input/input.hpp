#pragma once

#include <SFML/Window.hpp>

namespace WhitE {

class Input
{
private:
	Input();

	bool isKeyPressed(sf::Keyboard::Key key) { return sf::Keyboard::isKeyPressed(key); }
	bool isMouseButtonPressed(sf::Mouse::Button button) { return sf::Mouse::isButtonPressed(button); }
};

}
