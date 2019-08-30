#pragma once

#include "Renderer/layerType.hpp"

#include <list>
#include <string>

namespace WhitE {

class DrawableGameObject;

class Layer
{
public:
	Layer();
	Layer(const std::string& layerName);

	void addObjectToDrawables(DrawableGameObject* const object);

	void removeObjectFromDrawables(DrawableGameObject* const object);
	void removeObjectFromDrawables(const std::string& objectName);

	void clearDrawables();

	auto getDrawableObjects() const -> const std::list<DrawableGameObject*> & { return mDrawableObjects; }
	auto getLayerName() const -> std::string { return mLayerName; }

private:
	std::list<DrawableGameObject*> mDrawableObjects;
	std::string mLayerName;

};

}
