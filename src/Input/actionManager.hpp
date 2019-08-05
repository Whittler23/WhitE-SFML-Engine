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
	static void addAction(std::pair<std::string, sf::Keyboard::Key>);
	static void addAction(std::pair<std::string, sf::Keyboard::Key>);
	static void deleteAction(const std::string& actionName);
	static void deleteAction(const std::string& actionName);
	static bool isActionPressed(sf::Keyboard::Key key);
	static bool isActionPressed(sf::Mouse::Button button);

private:
	Input input;
	static ActionManager& getInstance();
};

}