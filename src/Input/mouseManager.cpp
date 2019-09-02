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

//=====================================================================

void MouseManager::readMouseWindowClickPosition()
{
	mLastMouseWindowClickPosition = mMouseWindowPosition;
}

sf::Vector2i MouseManager::getLastMouseWindowClickPosition()
{
	return mLastMouseWindowClickPosition;
}

void MouseManager::readMouseWindowPosition(const sf::Vector2i& mouseWindowPosition)
{
	mMouseWindowPosition = mouseWindowPosition;
}

sf::Vector2i MouseManager::getMouseWindowPosition()
{
	return mMouseWindowPosition;
}

//=====================================================================

void MouseManager::readMouseWorldPosition(const sf::Vector2f& mouseWorldPosition)
{
	mMouseWorldPosition = mouseWorldPosition;
}

sf::Vector2f MouseManager::getMouseWorldPosition()
{
	return mMouseWorldPosition;
}

void MouseManager::readMouseWorldClickPosition()
{
	mLastMouseWorldClickPosition = mMouseWorldPosition;
}

sf::Vector2f MouseManager::getLastMouseWorldClickPosition()
{
	return mLastMouseWorldClickPosition;
}

//======================================================================

void MouseManager::readMouseGuiPosition(const sf::Vector2f& mouseGuiPosition)
{
	mMouseGuiPosition = mouseGuiPosition;
}

sf::Vector2f MouseManager::getMouseGuiPosition()
{
	return mMouseGuiPosition;
}

void MouseManager::readMouseGuiClickPosition()
{
	mLastMouseGuiClickPosition = mMouseGuiPosition;
}

sf::Vector2f MouseManager::getLastMouseGuiClickPosition()
{
	return mLastMouseGuiClickPosition;
}

}