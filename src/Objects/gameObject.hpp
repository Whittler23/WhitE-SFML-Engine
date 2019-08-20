#pragma once

#include <SFML/System.hpp>

#include <string>

namespace WhitE {

class GameObject
{
public:
	GameObject(const std::string& name);

	virtual void update(const sf::Time& deltaTime) {}
	virtual void input() {}

private:
	const std::string mName;
};

}