#pragma once

#include <SFML/System/Vector2.hpp>

namespace WhitE::gui {

class WidgetProperties 
{
public:
	WidgetProperties();
	WidgetProperties(const sf::Vector2f& percentagePosition, const sf::Vector2f percentageSize, const sf::Vector2f& containerSize);
	WidgetProperties(float percentageXPosition, float percentageYPosition, float percentageWidth, float percentageHeight, const sf::Vector2f& containerSize);

	void recalculateValues(const sf::Vector2f& prevContainerSize, const sf::Vector2f& newContainerSize);

	void setPercentageSize(const sf::Vector2f& percentagePosition, const sf::Vector2f& containerSize);
	void setSize(const sf::Vector2f& size);
	sf::Vector2f getPercentageSize(const sf::Vector2f& containerSize) const;
	sf::Vector2f getSize() const;

	void setPercentagePosition(const sf::Vector2f& percentagePosition, const sf::Vector2f& containerSize);
	void setPosition(const sf::Vector2f& position);
	sf::Vector2f getPercentagePosition(const sf::Vector2f& containerSize) const;
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
