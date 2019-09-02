#pragma once

#include "Input/input.hpp"

#include <SFML/Window.hpp>

namespace WhitE {

class MouseManager
{
public:
	static bool isMouseButtonJustPressed(sf::Mouse::Button button);
	static bool isMouseButtonPressed(sf::Mouse::Button button);

	static void readMouseWindowClickPosition();
	static sf::Vector2i getLastMouseWindowClickPosition();

	static void readMouseWindowPosition(const sf::Vector2i& mouseWindowPosition);
	static sf::Vector2i getMouseWindowPosition();

	static void readMouseWorldClickPosition();
	static sf::Vector2f getLastMouseWorldClickPosition();

	static void readMouseWorldPosition(const sf::Vector2f& mouseWorldPosition);
	static sf::Vector2f getMouseWorldPosition();

	static void readMouseGuiClickPosition();
	static sf::Vector2f getLastMouseGuiClickPosition();

	static void readMouseGuiPosition(const sf::Vector2f& mouseGuiPosition);
	static sf::Vector2f getMouseGuiPosition();

private:
	inline static Input mInput;

	inline static sf::Vector2i mLastMouseWindowClickPosition;
	inline static sf::Vector2i mMouseWindowPosition;

	inline static sf::Vector2f mLastMouseWorldClickPosition;
	inline static sf::Vector2f mMouseWorldPosition;

	inline static sf::Vector2f mLastMouseGuiClickPosition;
	inline static sf::Vector2f mMouseGuiPosition;
};

}
