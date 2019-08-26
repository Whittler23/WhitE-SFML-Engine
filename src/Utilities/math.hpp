#pragma once

#include <SFML/Graphics.hpp>

namespace WhitE {

namespace Math
{
	sf::Vector2f getFloatRectCenter(const sf::FloatRect& floatRect);

	sf::Vector2f getPSofV(const float percent, const sf::Vector2f& size);
}

}