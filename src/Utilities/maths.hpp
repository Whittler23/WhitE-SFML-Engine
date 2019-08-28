#pragma once

#include <SFML/Graphics.hpp>

namespace WhitE {

namespace Math
{
	sf::Vector2f getRectCenter(const sf::FloatRect& floatRect);
	sf::Vector2f getRectCenter(const sf::Vector2f& rectSides);

	sf::Vector2f getPofV(const float percent, const sf::Vector2f& size);
	sf::Vector2f getPofV(const float percentX, const float percentY, const sf::Vector2f& size);
}

}