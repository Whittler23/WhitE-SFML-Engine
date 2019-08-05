#include "Input/actionManager.hpp"
#include "Logger/logs.hpp"

namespace WhitE {

ActionManager& ActionManager::getInstance()
{
	static ActionManager actionManager;
	return actionManager;
}

void ActionManager::addAction(const std::string& actionName, sf::Keyboard::Key key)
{
	getInstance().mKeyboardMap.insert(std::make_pair(actionName, std::vector<sf::Keyboard::Key> {key}));

	WE_LOG_INFO(actionName + " action was added to the manager.");
}

void ActionManager::addAction(const std::string& actionName, std::vector<sf::Keyboard::Key> keys)
{
	getInstance().mKeyboardMap.insert(std::make_pair(actionName, keys));
}

void ActionManager::addAction(const std::string& actionName, sf::Mouse::Button button)
{
	getInstance().mMouseMap.insert(std::make_pair(actionName, button));

	WE_LOG_INFO(actionName + " action was added to the manager.");
}

void ActionManager::deleteAction(const std::string& actionName)
{
	if (getInstance().mKeyboardMap.find(actionName) != getInstance().mKeyboardMap.end())
		getInstance().mKeyboardMap.erase(actionName);
	else
		WE_LOG_ERROR("WhitE: Key of map cannot be found!");
}

bool ActionManager::isActionPressed(const std::string& actionName)
{
	if (getInstance().mKeyboardMap.count(actionName))
		return handleKeyboard(actionName) ? true : false;
	else
		return handleMouse(actionName) ? true : false;
}

bool ActionManager::handleKeyboard(const std::string& actionName)
{
	auto keys = getInstance().mKeyboardMap.at(actionName);
	for (const auto& key : keys)
	{
		if (getInstance().input.isKeyPressed(key))
			return true;
	}
	return false;
}

bool ActionManager::handleMouse(const std::string& actionName)
{
	auto buttons = getInstance().mMouseMap.at(actionName);
	if (getInstance().input.isMouseButtonPressed(buttons))
		return true;
	return false;
}

}