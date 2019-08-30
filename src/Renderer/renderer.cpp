#include "Renderer/renderer.hpp"
#include "Objects/drawableGameObject.hpp"
#include "Objects/gameEngineObject.hpp"
#include "Logger/logs.hpp"
#include "window.hpp"

namespace WhitE {

Renderer::Renderer(sf::RenderTarget& renderTarget)
	:mRenderTarget(renderTarget)
	,mCamera(renderTarget)
{
	WE_CORE_INFO("Initialized engine renderer");
}

Renderer::~Renderer()
{
	WE_CORE_INFO("Deleted engine renderer");
	clearDrawableGameEngineObjects();
}

void Renderer::update(const sf::Time deltaTime)
{
	mCamera.update(deltaTime);
}

void Renderer::draw() const
{
	drawGameEngineObjects();
}

void Renderer::drawGameEngineObjects() const
{
	for (auto& gameEngineObject : mGameEngineObjects)
		mRenderTarget.draw(*gameEngineObject);
}

void Renderer::addGameEngineObject(GameEngineObject* const gameEngineObject)
{
	mGameEngineObjects.emplace_back(gameEngineObject);

	WE_CORE_INFO("\"" + gameEngineObject->getName() + "\" was added to game engine objects");
}

void Renderer::removeGameEngineObject(const std::string& gameEngineObjectName)
{
	for (auto it = mGameEngineObjects.begin(); it != mGameEngineObjects.end(); ++it)
	{
		if ((*it)->getName() == gameEngineObjectName)
		{
			mGameEngineObjects.erase(it);
			WE_CORE_INFO("\"" + gameEngineObjectName + "\" was removed from game engine objects");
			return;
		}
	}

	WE_CORE_WARNING("\"" + gameEngineObjectName + "\" could not be removed from game engine objects");
}

void Renderer::clearDrawableGameEngineObjects()
{
	mGameEngineObjects.clear();

	WE_CORE_INFO("Drawable objects were removed from all layers");
}

}