#pragma once

#include "Gui/GuiElements/button.hpp"
#include "Gui/guiElement.hpp"
#include "Input/mouseManager.hpp"
#include "Utilities/maths.hpp"

namespace WhitE {

Button::Button(SharedData& sharedData, const sf::Vector2f& percentPosition, const sf::Vector2f& percentSize, const std::string& text)
	:GuiElement(sharedData, "Button")
	,mButtonText(text, mSharedData.mResourcesHolder.getFontHolder().get("testFont"))
	,mIdleColor(50, 206, 209, 120)
	,mHoverColor(50, 206, 209, 200)
	,mPressColor(255, 0, 0, 200)
{
	init(percentPosition, percentSize);
}

Button::~Button()
{

}

void Button::init(const sf::Vector2f& percentPosition, const sf::Vector2f& percentSize)
{

	mButtonBackground.setPosition(Math::getPofV(percentPosition.x, percentPosition.y, mSharedData.mCamera.getDefaultView().getSize()));
	mButtonBackground.setSize(Math::getPofV(percentSize.x, percentSize.y, mSharedData.mCamera.getDefaultView().getSize()));
	mButtonBackground.setFillColor(mIdleColor);

	mButtonText.setCharacterSize(25);
	mButtonText.setPosition(
		mButtonBackground.getPosition().x + mButtonBackground.getSize().x / 2 - mButtonText.getGlobalBounds().width / 2.f,
		mButtonBackground.getPosition().y + mButtonBackground.getSize().y / 2 - mButtonText.getGlobalBounds().height / 2.f
	);
	mButtonText.move(sf::Vector2f(0, -5.f));
}

void Button::input()
{
	if (mButtonBackground.getGlobalBounds().contains(sf::Vector2f(MouseManager::getMouseGuiPosition())))
	{
		mButtonState = ButtonState::Hover;
		if (MouseManager::isMouseButtonJustPressed(sf::Mouse::Left))
			mButtonState = ButtonState::Press;
	}
	else
		mButtonState = ButtonState::Idle;
}

void Button::update(const sf::Time& deltaTime)
{
	switch (mButtonState)
	{
	case ButtonState::Idle:
		onIdle();
		break;
	case ButtonState::Hover:
		onHover();
		break;
	case ButtonState::Press:
		onPress();
		break;
	}
}

void Button::draw(sf::RenderTarget & rt, sf::RenderStates) const
{
	rt.draw(mButtonBackground);
	rt.draw(mButtonText);
}

bool Button::isPressed()
{
	return (mButtonState == ButtonState::Press);
}

void Button::onIdle()
{
	mButtonBackground.setFillColor(mIdleColor);
}

void Button::onHover()
{
	mButtonBackground.setFillColor(mHoverColor);
}

void Button::onPress()
{
	mButtonBackground.setFillColor(mPressColor);
}

}