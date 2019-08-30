#include "maths.hpp"

namespace WhitE {

namespace Math
{
	sf::Vector2f getRectCenter(const sf::FloatRect& floatRect)
	{
		return sf::Vector2f(
			floatRect.left + floatRect.width/2.f,
			floatRect.top + floatRect.height/2.f
		);
	}

	sf::Vector2f getRectCenter(const sf::Vector2f& rectSides)
	{
		return sf::Vector2f(
			rectSides.x/2.f,
			rectSides.y/2.f
		);
	}

	sf::Vector2f getPofV(const float percent, const sf::Vector2f& size)
	{
		return sf::Vector2f(
			size.x * (percent / 100),
			size.y * (percent / 100)
		);
	}

	sf::Vector2f getPofV(const float percentX, const float percentY, const sf::Vector2f& size)
	{
		return sf::Vector2f(
			size.x * (percentX / 100),
			size.y * (percentY / 100)
		);
	}
}

}