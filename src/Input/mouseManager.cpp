#include "Input/mouseManager.hpp"
#include "Input/eventManager.hpp"

namespace WhitE {

bool MouseManager::isMouseButtonPressed(sf::Mouse::Button button)
{
	return EventManager::getIsButtonPressed() && EventManager::getLastPressedButton() == button;
}

bool MouseManager::isMouseButtonJustPressed(sf::Mouse::Button button)
{
	return mInput.isMouseButtonJustPressed(button) ? true : false;
}

void MouseManager::readMouseClickPosition(const sf::Vector2i& mouseClickPosition)
{
	mLastMouseClickPosition = mouseClickPosition;
}

sf::Vector2i MouseManager::getLastMouseClickPosition()
{
	return mLastMouseClickPosition;
}

void MouseManager::readMouseWorldPosition(const sf::Vector2f& mouseWorldPosition)
{
	mMouseWorldPosition = mouseWorldPosition;
}

sf::Vector2f MouseManager::getMouseWorldPosition()
{
	return mMouseWorldPosition;
}

void MouseManager::readMouseWindowPosition(const sf::Vector2i& mouseWindowPosition)
{
	mMouseWindowPosition = mouseWindowPosition;
}

sf::Vector2i MouseManager::getMouseWindowPosition()
{
	return mMouseWindowPosition;
}

}