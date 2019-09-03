#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <list>

namespace WhitE {

class Entity : public sf::Drawable
{
public:
	Entity(const std::string& name);

	virtual void update(const sf::Time& deltaTime);
	virtual void input();

	auto getName() const -> std::string { return mName; }
	void setName(const std::string& name) { mName = name; }

private:
	std::string mName;
};

}