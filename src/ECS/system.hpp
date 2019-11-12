#pragma once

#include <SFML/System/Clock.hpp>
#include "entt/entt.hpp"

namespace WhitE::sys {

class System
{
public:
	explicit System(entt::registry& registry);

	virtual void update(const sf::Time deltaTime) = 0;

protected:
	entt::registry& mRegistry;

};

}
