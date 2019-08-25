#pragma once

#include "Input/input.hpp"

#include <SFML/Window.hpp>

namespace WhitE {

class MouseManager
{
public:
	static bool isMouseButtonJustPressed(sf::Mouse::Button);
	static bool isMouseButtonPressed(sf::Mouse::Button);
	static void readMouseClickPosition(const sf::Vector2i& mouseClickPosition);
	static sf::Vector2i getLastMouseClickPosition();

	static void readMousePosition(const sf::Vector2i& mousePosition);
	static sf::Vector2i getMousePosition();

private:
	inline static Input mInput;
	inline static sf::Vector2i mLastMouseClickPosition;
	inline static sf::Vector2i mMousePosition;
};

}
