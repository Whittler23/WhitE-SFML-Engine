#pragma once

#include "Gui/widgetProperties.hpp"

namespace WhitE::gui {

/////////////////////////////////////////////////////////////
					//CONSTRUCTORS
/////////////////////////////////////////////////////////////

WidgetProperties::WidgetProperties()
	:mXAxisPosition(0.f)
	,mYAxisPosition(0.f)
	,mWidth(0.f)
	,mHeight(0.f)
{
}

WidgetProperties::WidgetProperties(const sf::Vector2f& percentagePosition, const sf::Vector2f percentageSize, const sf::Vector2f& viewSize)
{
	setPercentagePosition(percentagePosition, viewSize);
	setPercentagePosition(percentageSize, viewSize);
}

WidgetProperties::WidgetProperties(float percentageXPosition, float percentageYPosition, float percentageWidth, float percentageHeight, const sf::Vector2f& viewSize)
{
	setPercentagePosition(sf::Vector2f(percentageXPosition, percentageYPosition), viewSize);
	setPercentagePosition(sf::Vector2f(percentageWidth, percentageHeight), viewSize);
}

/////////////////////////////////////////////////////////////
						//PUBLIC
/////////////////////////////////////////////////////////////

void WidgetProperties::setPercentagePosition(const sf::Vector2f& percentagePosition, const sf::Vector2f& viewSize)
{
	mXAxisPosition = getValueFromPercent(percentagePosition.x, viewSize.x);
	mYAxisPosition = getValueFromPercent(percentagePosition.y, viewSize.y);
}

void WidgetProperties::setPosition(const sf::Vector2f& position)
{
	mXAxisPosition = position.x;
	mYAxisPosition = position.y;
}

void WidgetProperties::setPercentageSize(const sf::Vector2f& percentageSize, const sf::Vector2f& viewSize)
{
	mWidth = getValueFromPercent(percentageSize.x, viewSize.x);
	mHeight = getValueFromPercent(percentageSize.y, viewSize.y);
}

void WidgetProperties::setSize(const sf::Vector2f& size)
{
	mWidth = size.x;
	mHeight = size.y;
}

sf::Vector2f WidgetProperties::getPercentageSize(const sf::Vector2f& containerSize) const
{
	float percentX = mWidth / containerSize.x * 100.f;
	float percentY = mHeight / containerSize.y * 100.f;
	return sf::Vector2f(percentX, percentY);
}

sf::Vector2f WidgetProperties::getPercentagePosition(const sf::Vector2f& containerSize) const
{
	float percentX = mXAxisPosition / containerSize.x * 100.f;
	float percentY = mYAxisPosition / containerSize.y * 100.f;
	return sf::Vector2f(percentX, percentY);
}

sf::Vector2f WidgetProperties::getPosition() const
{
	return sf::Vector2f(mXAxisPosition, mYAxisPosition);
}

sf::Vector2f WidgetProperties::getSize() const
{
	return sf::Vector2f(mWidth, mHeight);
}

sf::Vector2f WidgetProperties::getPercentFromValues(const sf::Vector2f& firstValue, const sf::Vector2f& secondValue)
{
	float firstPercentageValue = firstValue.x / secondValue.x * 100.f;
	float secondPercentageValue = firstValue.y / secondValue.y * 100.f;
	return sf::Vector2f(firstPercentageValue, secondPercentageValue);
}

float WidgetProperties::getValueFromPercent(float percentageValue, float value)
{
	return value * (percentageValue / 100);
}

/////////////////////////////////////////////////////////////
						//PRIVATE
/////////////////////////////////////////////////////////////

void WidgetProperties::recalculateValues(const sf::Vector2f& prevViewSize, const sf::Vector2f& newViewSize)
{
	sf::Vector2f percentPosition = getPercentFromValues(sf::Vector2f(mXAxisPosition ,mYAxisPosition), prevViewSize);
	sf::Vector2f percentSize = getPercentFromValues(sf::Vector2f(mWidth, mHeight), prevViewSize);
	
	setPercentagePosition(percentPosition, newViewSize);
	setPercentageSize(percentSize, newViewSize);
}

/////////////////////////////////////////////////////////////

}
