#include "Input/actionManager.hpp"
#include "Logger/logs.hpp"

namespace WhitE {

void ActionManager::addAction(const std::string& actionName, sf::Keyboard::Key key)
{
	mKeyboardMap.insert(std::make_pair(actionName, std::vector<sf::Keyboard::Key> {key}));

	WE_CORE_INFO(actionName + " action was added to the manager.");
}

void ActionManager::addAction(const std::string& actionName, std::vector<sf::Keyboard::Key> keys)
{
	mKeyboardMap.insert(std::make_pair(actionName, keys));
}

void ActionManager::deleteAction(const std::string& actionName)
{
	if (mKeyboardMap.find(actionName) != mKeyboardMap.end())
		mKeyboardMap.erase(actionName);
	else
		WE_CORE_WARNING("Key of map cannot be found!");
}

bool ActionManager::isActionPressed(const std::string& actionName) 
{
	auto keys = mKeyboardMap.at(actionName);
	for (const auto& key : keys)
	{
		if (mInput.isKeyPressed(key))
			return true;
	}
	return false;
}

}