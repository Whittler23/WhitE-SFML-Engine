#pragma once

#include <SFML/Window.hpp>

namespace WhitE {

class Input
{
private:
	bool isKeyJustPressed(sf::Keyboard::Key key) { return sf::Keyboard::isKeyPressed(key); }
	bool isMouseButtonJustPressed(sf::Mouse::Button button) { return sf::Mouse::isButtonPressed(button); }

	friend class ActionManager;
	friend class MouseManager;
};

}
