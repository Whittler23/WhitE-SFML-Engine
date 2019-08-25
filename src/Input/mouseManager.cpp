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

void MouseManager::readMousePosition(const sf::Vector2i& mousePosition)
{
	mMousePosition = mousePosition;
}

sf::Vector2i MouseManager::getMousePosition()
{
	return mMousePosition;
}

}