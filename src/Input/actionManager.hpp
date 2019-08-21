#pragma once

#include "Input/input.hpp"

#include <unordered_map>

namespace WhitE {

class ActionManager
{
public:
	static void addAction(const std::string&, sf::Keyboard::Key);
	static void addAction(const std::string&, std::vector<sf::Keyboard::Key>);

	static void deleteAction(const std::string& actionName);
	static bool isActionPressed(const std::string& actionName);

	static bool isMouseButtonPressed(sf::Mouse::Button);
	static void readMouseClickPosition(const sf::Vector2i& mouseClickPosition);
	static sf::Vector2i getLastMouseClickPosition();

	static void readMousePosition(const sf::Vector2i& mousePosition);
	static sf::Vector2i getMousePosition();

private:
	inline static Input mInput;
	inline static std::unordered_map<std::string, std::vector<sf::Keyboard::Key>> mKeyboardMap;
	inline static sf::Vector2i mLastMouseClickPosition;
	inline static sf::Vector2i mMousePosition;
};

}