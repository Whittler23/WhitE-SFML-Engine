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

private:
	inline static Input mInput;
	inline static std::unordered_map<std::string, std::vector<sf::Keyboard::Key>> mKeyboardMap;
};

}