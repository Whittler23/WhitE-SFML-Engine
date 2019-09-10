#pragma once

#include "Gui/GuiElements/button.hpp"
#include "Gui/guiElement.hpp"
#include "Input/mouseManager.hpp"
#include "Utilities/maths.hpp"

namespace WhitE {

	Button::Button(SharedData& sharedData, const sf::Vector2f& percentPosition, const sf::Vector2f& percentSize,
		sf::Color idleColor, sf::Color hoverColor, sf::Color pressColor,
		const std::string& text, const float buttonOutlines, const unsigned fontSize,
		const std::string& textureName, const std::string& fontName)
	:GuiElement(sharedData, "Button")
	,mButtonState(ButtonState::Idle)
	,mButtonText(text, sf::Font())
	,mIdleColor(idleColor)
	,mHoverColor(hoverColor)
	,mPressColor(pressColor)
{
	loadGraphics(textureName, fontName);
	init(percentPosition, percentSize, buttonOutlines, fontSize);
}

Button::~Button()
{

}

void Button::loadGraphics(const std::string& textureName, const std::string& fontName)
{
	if (fontName == "")
		mButtonText.setFont(mSharedData.getFonts().get("testFont"));
	else
		mButtonText.setFont(mSharedData.getFonts().get(fontName));

	if (textureName != "")
		mButtonBox.setTexture(&mSharedData.getTextures().get(textureName));
}

void Button::init(const sf::Vector2f& percentPosition, const sf::Vector2f& percentSize, const float buttonOutlines, const unsigned fontSize)
{
	mButtonBox.setPosition(Math::getPofV(percentPosition.x, percentPosition.y, mSharedData.mCamera.getDefaultView().getSize()));
	mButtonBox.setSize(Math::getPofV(percentSize.x, percentSize.y, mSharedData.mCamera.getDefaultView().getSize()));
	mButtonBox.setOutlineThickness(buttonOutlines);

	mButtonText.setCharacterSize(fontSize);
	mButtonText.setPosition(getTextPosition());
}

sf::Vector2f Button::getTextPosition()
{
	auto textBounds(mButtonText.getGlobalBounds());
	auto buttonBox(mButtonBox.getSize());
	mButtonText.setOrigin((textBounds.width - buttonBox.x) / 2 + textBounds.left,
		(textBounds.height - buttonBox.y) / 2 + textBounds.top);

	return sf::Vector2f(mButtonBox.getPosition().x,
		mButtonBox.getPosition().y);
}

void Button::input()
{
	if (mButtonBox.getGlobalBounds().contains(sf::Vector2f(MouseManager::getMouseGuiPosition())))
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

void Button::draw(sf::RenderTarget & rt, sf::RenderStates rs) const
{
	rt.draw(mButtonBox);
	rt.draw(mButtonText);
}

bool Button::isPressed()
{
	return (mButtonState == ButtonState::Press);
}

void Button::onIdle()
{
	mButtonBox.setFillColor(mIdleColor);
}

void Button::onHover()
{
	mButtonBox.setFillColor(mHoverColor);
}

void Button::onPress()
{
	mButtonBox.setFillColor(mPressColor);
}

}