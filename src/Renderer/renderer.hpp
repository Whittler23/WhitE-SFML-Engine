#pragma once

#include <SFML/Graphics.hpp>

#include <set>

namespace WhitE {

class Renderer
{
public:
	Renderer(sf::RenderTarget& renderTarget);
	~Renderer();

	void update();
	void draw() ;

	void addObject(const sf::Drawable& object) const;
	void removeObject(const sf::Drawable& object) const;

private:
	sf::RenderTarget& mRenderTarget;
	std::multiset<sf::Drawable*> mDrawableSet;
};

}
