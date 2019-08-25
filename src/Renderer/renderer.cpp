#include "Renderer/renderer.hpp"
#include "Objects/drawableGameObject.hpp"
#include "Objects/gameEngineObject.hpp"
#include "Logger/logs.hpp"
#include "window.hpp"

namespace WhitE {

Renderer::Renderer(sf::RenderTarget& renderTarget)
	:mRenderTarget(renderTarget)
{
	init();
	WE_CORE_INFO("Initialized state renderer");
}

Renderer::~Renderer()
{
	WE_CORE_INFO("Deleted state renderer");
	clearDrawables();
}

void Renderer::init()
{
	mLayerNames = { { LayerType::Background, "BackgroundLayer" },
				{ LayerType::StaticObjects, "StaticObjectsLayer" },
				{ LayerType::KinematicObjects, "KinematicObjectsLayer" } };

	mLayers = { {LayerType::Background, Layer(getLayerName(LayerType::Background))},
			{LayerType::StaticObjects, Layer(getLayerName(LayerType::StaticObjects))},
			{LayerType::KinematicObjects, Layer(getLayerName(LayerType::KinematicObjects))} };

}

void Renderer::draw() const
{
	for (auto& layer : mLayers)
		for (auto drawableObject : layer.second.getDrawableObjects())
			mRenderTarget.draw(*drawableObject);

	drawGameEngineObjects();
}

void Renderer::drawGameEngineObjects() const
{
	for (auto& gameEngineObject : mGameEngineObjects)
		mRenderTarget.draw(*gameEngineObject);
}

void Renderer::addObjectToDrawables(LayerType layerType, DrawableGameObject* const object)
{
	mLayers[layerType].addObjectToDrawables(object);

	WE_CORE_INFO("\"" + object->getName() + "\" was added to " + getLayerName(layerType));
}

void Renderer::addGameEngineObject(GameEngineObject* const gameEngineObject)
{
	mGameEngineObjects.emplace_back(gameEngineObject);

	WE_CORE_INFO("\"" + gameEngineObject->getName() + "\" was added to game engine objects");
}

void Renderer::removeObjectFromDrawables(LayerType layerType, DrawableGameObject* const object)
{
	mLayers[layerType].removeObjectFromDrawables(object);

	WE_CORE_INFO("\"" + object->getName() + "\" was removed from " + getLayerName(layerType));
}

void Renderer::removeObjectFromDrawables(const std::string& objectName)
{
	for (auto& layer : mLayers)
		layer.second.removeObjectFromDrawables(objectName);

	WE_CORE_INFO("\"" + objectName + "\" was removed from layers it existed in");
}

void Renderer::removeObjectFromDrawables(LayerType layerType, const std::string& objectName)
{
	mLayers[layerType].removeObjectFromDrawables(objectName);

	WE_CORE_INFO("\"" + objectName + "\" was removed from " + getLayerName(layerType));
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

void Renderer::clearDrawables(LayerType layerType)
{
	mLayers[layerType].clearDrawables();

	WE_CORE_INFO("Drawable objects were removed from " + getLayerName(layerType));
}

void Renderer::clearDrawables()
{
	for (auto& layer : mLayers)
		layer.second.clearDrawables();

	WE_CORE_INFO("Drawable objects were removed from all layers");
}

std::string Renderer::getLayerName(LayerType layerType)
{
	return mLayerNames[layerType];
}

}