#include "Renderer/layer.hpp"
#include "Objects/drawableGameObject.hpp"
#include "Logger/logs.hpp"

namespace WhitE {

Layer::Layer()
	:mLayerName("UnknownLayer")
{
}

Layer::Layer(const std::string& layerName)
	:mLayerName(layerName)
{
}

void Layer::addObjectToDrawables(DrawableGameObject* const object)
{
	mDrawableObjects.emplace_back(object);
}

void Layer::removeObjectFromDrawables(DrawableGameObject* const object)
{
	for (auto it = mDrawableObjects.begin(); it != mDrawableObjects.end(); ++it)
	{
		if (*it = object)
		{
			mDrawableObjects.erase(it);
			return;
		}
	}
}

void Layer::removeObjectFromDrawables(const std::string& objectName)
{
	for (auto& it = mDrawableObjects.begin(); it != mDrawableObjects.end(); ++it)
	{
		if ((*it)->getName() == objectName)
		{
			mDrawableObjects.erase(it);
			return;
		}
	}
}

void Layer::clearDrawables()
{
	mDrawableObjects.clear();
}

}