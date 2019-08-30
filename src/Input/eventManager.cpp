#include "Input/eventManager.hpp"

namespace WhitE {

bool EventManager::getIsKeyPressed()
{
	return mIsKeyPressed;
}

bool EventManager::getIsKeyReleased()
{
	return mIsKeyReleased;
}

bool EventManager::getIsButtonPressed()
{
	return mIsButtonPressed;
}

bool EventManager::getIsButtonReleased()
{
	return mIsButtonReleased;
}

sf::Keyboard::Key EventManager::getLastPressedKey()
{
	return mLastPressedKey;
}

sf::Keyboard::Key EventManager::getLastReleasedKey()
{
	return mLastReleasedKey;
}

sf::Mouse::Button EventManager::getLastPressedButton()
{
	return mLastPressedButton;
}

sf::Mouse::Button EventManager::getLastReleasedButton()
{
	return mLastReleasedButton;
}

void EventManager::setIsKeyPressed(const bool isKeyPressed)
{
	mIsKeyPressed = isKeyPressed;
}

void EventManager::setIsKeyReleased(const bool isKeyReleased)
{
	mIsKeyReleased = isKeyReleased;
}

void EventManager::setIsButtonPressed(const bool isButtonPressed)
{
	mIsButtonPressed = isButtonPressed;
}

void EventManager::setIsButtonReleased(const bool isButtonReleased)
{
	mIsButtonReleased = isButtonReleased;
}

void EventManager::setLastPressedKey(sf::Keyboard::Key key)
{
	mLastPressedKey = key;
}

void EventManager::setLastReleasedKey(sf::Keyboard::Key key)
{
	mLastReleasedKey = key;
}

void EventManager::setLastPressedButton(sf::Mouse::Button button)
{
	mLastPressedButton = button;
}

void EventManager::setLastReleasedButton(sf::Mouse::Button button)
{
	mLastReleasedButton = button;
}

void EventManager::clear()
{
	mIsKeyPressed = false;
	mIsKeyReleased = false;
	mIsButtonPressed = false;
	mIsButtonReleased = false;
	mLastPressedKey = sf::Keyboard::Unknown;
	mLastReleasedKey = sf::Keyboard::Unknown;
	mLastPressedButton = sf::Mouse::Button::ButtonCount;
	mLastReleasedButton = sf::Mouse::ButtonCount;
}

}