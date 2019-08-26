#pragma once

#include "Input/input.hpp"

#include <SFML/Window.hpp>

namespace WhitE {

class MouseManager
{
public:
	static bool isMouseButtonJustPressed(sf::Mouse::Button button);
	static bool isMouseButtonPressed(sf::Mouse::Button button);
	static void readMouseClickPosition(const sf::Vector2i& mouseClickPosition);
	static sf::Vector2i getLastMouseClickPosition();

	static void readMouseWindowPosition(const sf::Vector2i& mouseWindowPosition);
	static sf::Vector2i getMouseWindowPosition();
	static void readMouseWorldPosition(const sf::Vector2f& mouseWorldPosition);
	static sf::Vector2f getMouseWorldPosition();

private:
	inline static Input mInput;
	inline static sf::Vector2i mLastMouseClickPosition;
	inline static sf::Vector2i mMouseWindowPosition;
	inline static sf::Vector2f mMouseWorldPosition;
};

}
