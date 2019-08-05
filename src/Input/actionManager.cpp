#include "Input/actionManager.hpp"
#include "Logger/logs.hpp"

namespace WhitE {

void ActionManager::addAction(const std::string& actionName, sf::Keyboard::Key key)
{
	mKeyboardMap.insert(std::make_pair(actionName, std::vector<sf::Keyboard::Key> {key}));

	WE_LOG_INFO(actionName + " action was added to the manager.");
}

void ActionManager::addAction(const std::string& actionName, std::vector<sf::Keyboard::Key> keys)
{
	mKeyboardMap.insert(std::make_pair(actionName, keys));
}

void ActionManager::addAction(const std::string& actionName, sf::Mouse::Button button)
{
	mMouseMap.insert(std::make_pair(actionName, button));

	WE_LOG_INFO(actionName + " action was added to the manager.");
}

void ActionManager::deleteAction(const std::string& actionName)
{
	if (mKeyboardMap.find(actionName) != mKeyboardMap.end())
		mKeyboardMap.erase(actionName);
	else
		WE_LOG_ERROR("WhitE: Key of map cannot be found!");
}

bool ActionManager::isActionPressed(const std::string& actionName)
{
	if (mKeyboardMap.count(actionName))
		return handleKeyboard(actionName) ? true : false;
	else
		return handleMouse(actionName) ? true : false;
}

bool ActionManager::handleKeyboard(const std::string& actionName)
{
	auto keys = mKeyboardMap.at(actionName);
	for (const auto& key : keys)
	{
		if (mInput.isKeyPressed(key))
			return true;
	}
	return false;
}

bool ActionManager::handleMouse(const std::string& actionName)
{
	auto buttons = mMouseMap.at(actionName);
	if (mInput.isMouseButtonPressed(buttons))
		return true;
	return false;
}

}