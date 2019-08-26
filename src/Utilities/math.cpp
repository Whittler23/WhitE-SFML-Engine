#include "math.hpp"

namespace WhitE {

namespace Math
{
	sf::Vector2f getFloatRectCenter(const sf::FloatRect& floatRect)
	{
		return sf::Vector2f(
			floatRect.left + floatRect.width/2.f,
			floatRect.top + floatRect.height/2.f
		);
	}

	sf::Vector2f getPSofV(const float percent, const sf::Vector2f& size)
	{
		return sf::Vector2f(
			size.x * (percent / 100),
			size.y * (percent / 100)
		);
	}
}

}