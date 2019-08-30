#include "cast.hpp"

namespace WhitE {

namespace Cast
{
	std::string toString(const sf::Vector2f& mathVector)
	{
		return std::string("x:" + std::to_string(mathVector.x) + "y:" + std::to_string(mathVector.y));
	}

	std::string toString(const sf::Vector2i& mathVector)
	{
		return std::string("x:" + std::to_string(mathVector.x) + "y:" + std::to_string(mathVector.y));
	}
}

}