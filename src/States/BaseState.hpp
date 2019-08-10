#pragma once

#include "Resources/resourcesManager.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

namespace WhitE {

	class ResourcesHolder;

class BaseState
{
public:
	BaseState();
	virtual ~BaseState();

	virtual void onPop() = 0;
	virtual void onPush() = 0;

	virtual void draw() const = 0;
	virtual void update(const sf::Time& deltaTime) = 0;

protected:
	sf::Clock mStateTimer;
};

}
