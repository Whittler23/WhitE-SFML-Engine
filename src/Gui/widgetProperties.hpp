#pragma once

#include <SFML/System/Vector2.hpp>

namespace WhitE::gui {

class WidgetProperties 
{
public:
	WidgetProperties();
	WidgetProperties(const sf::Vector2f& percentagePosition, const sf::Vector2f percentageSize, const sf::Vector2f& viewSize);
	WidgetProperties(float percentageXPosition, float percentageYPosition, float percentageWidth, float percentageHeight, const sf::Vector2f& viewSize);

	void recalculateValues(const sf::Vector2f& prevViewSize, const sf::Vector2f& newViewSize);

	void setSize(const sf::Vector2f& percentageSize, const sf::Vector2f& viewSize);
	sf::Vector2f getSize() const;

	void setPosition(const sf::Vector2f& percentagePosition, const sf::Vector2f& viewSize);
	sf::Vector2f getPosition() const;

private:
	sf::Vector2f getPercentFromValues(const sf::Vector2f& firstValue, const sf::Vector2f& secondValue);
	float getValueFromPercent(float percentageValue, float value);

private:
	float mXAxisPosition;
	float mYAxisPosition;
	float mWidth;
	float mHeight;
};

}
