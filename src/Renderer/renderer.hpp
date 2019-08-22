#pragma once

#include <SFML/Graphics.hpp>

#include <list>

namespace WhitE {

class DrawableGameObject;

class Renderer
{
public:
	Renderer(sf::RenderTarget& renderTarget);
	~Renderer();

	void draw() const;

	void addObjectToDrawables(DrawableGameObject* const object);

	void removeObjectFromDrawables(DrawableGameObject* const object);
	void removeObjectFromDrawables(const std::string& objectName);

private:
	sf::RenderTarget& mRenderTarget;
	std::list<DrawableGameObject*> mDrawableObjects;
};

}
