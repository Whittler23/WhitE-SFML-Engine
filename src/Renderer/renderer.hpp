#pragma once

#include <SFML/Graphics.hpp>

#include <set>

namespace WhitE {

class Renderer
{
public:
	Renderer();

	void update();
	void draw() const;

	void addObject(const sf::Drawable& object) const;
	void removeObject(const sf::Drawable& object) const;

private:
	std::multiset<sf::Drawable> mObjectsToDraw;
};

}
