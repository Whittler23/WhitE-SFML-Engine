#include "Renderer/renderer.hpp"
#include "Objects/drawableGameObject.hpp"
#include "Logger/logs.hpp"
#include "Window/window.hpp"

namespace WhitE {

Renderer::Renderer(sf::RenderTarget& renderTarget)
	:mRenderTarget(renderTarget)
{
	WE_CORE_INFO("Initialized state renderer");
}

Renderer::~Renderer()
{
	WE_CORE_INFO("Deleted state renderer");
}

void Renderer::draw() const
{
	for (auto& drawableObject : mDrawableObjects)
	{
		mRenderTarget.draw(*drawableObject);
	}
}

void Renderer::addObjectToDrawables(DrawableGameObject* const object)
{
	mDrawableObjects.emplace_back(object);

	WE_CORE_INFO("\"" + object->getName() + "\" was added to rendered objects");
}

void Renderer::removeObjectFromDrawables(DrawableGameObject* const object)
{
	for (auto it = mDrawableObjects.begin(); it != mDrawableObjects.end(); ++it)
	{
		if (*it = object)
		{
			WE_CORE_INFO("\"" + object->getName() + "\" was removed from rendered objects");
			mDrawableObjects.erase(it);
			return;
		}
	}
}

void Renderer::removeObjectFromDrawables(const std::string& objectName)
{
	for (auto& it = mDrawableObjects.begin(); it != mDrawableObjects.end(); ++it)
	{
		if ((*it)->getName() == objectName)
		{
			WE_CORE_INFO("\"" + objectName + "\" was removed from rendered objects");
			mDrawableObjects.erase(it);
			return;
		}
	}
}

}