#pragma once

#include "Input/input.hpp"

#include <unordered_map>

namespace WhitE {

class ActionManager
{
private:
	ActionManager() = default;
	ActionManager(const ActionManager&) = delete;
	ActionManager& operator=(const ActionManager&) = delete;

public:
	static void addAction(const std::string&, sf::Keyboard::Key);
	static void addAction(const std::string&, std::vector<sf::Keyboard::Key>);
	static void addAction(const std::string&, sf::Mouse::Button);

	static void deleteAction(const std::string& actionName);
	static bool isActionPressed(const std::string& actionName);

private:
	static bool handleMouse(const std::string& actionName);
	static bool handleKeyboard(const std::string& actionName);

private:
	Input input;
	std::unordered_map<std::string, std::vector<sf::Keyboard::Key>> mKeyboardMap;
	std::unordered_map<std::string, sf::Mouse::Button> mMouseMap;

	static ActionManager& getInstance();
};

}