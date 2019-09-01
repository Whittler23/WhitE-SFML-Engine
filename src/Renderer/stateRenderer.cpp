#include "Renderer/stateRenderer.hpp"
#include "Objects/drawableGameObject.hpp"
#include "Gui/guiElement.hpp"
#include "Logger/logs.hpp"

namespace WhitE {

StateRenderer::StateRenderer(sf::RenderTarget& renderTarget)
	:mRenderTarget(renderTarget)
	,mGui(nullptr)
{
	init();
	WE_CORE_INFO("Initialized state renderer");
}

StateRenderer::~StateRenderer()
{
	WE_CORE_INFO("Deleted state renderer");
}

void StateRenderer::init()
{
	mLayerNames = { { LayerType::Background, "BackgroundLayer" },
				{ LayerType::StaticObjects, "StaticObjectsLayer" },
				{ LayerType::KinematicObjects, "KinematicObjectsLayer" } };

	mLayers = { {LayerType::Background, Layer(getLayerName(LayerType::Background))},
			{LayerType::StaticObjects, Layer(getLayerName(LayerType::StaticObjects))},
			{LayerType::KinematicObjects, Layer(getLayerName(LayerType::KinematicObjects))} };
}

void StateRenderer::draw() const
{
	for (auto& layer : mLayers)
		for (auto drawableObject : layer.second.getDrawableObjects())
			if(drawableObject->getVisibility())
				mRenderTarget.draw(*drawableObject);

	if (mGui != nullptr)
		drawGui();
}

void StateRenderer::drawGui() const
{
	for (auto& guiElement : *mGui)
		mRenderTarget.draw(*guiElement);
}

void StateRenderer::attachGui(std::list<std::unique_ptr<GuiElement>>* gui)
{
	mGui = gui;
}

void StateRenderer::removeGui()
{
	mGui = nullptr;
}

void StateRenderer::addObjectToDrawables(LayerType layerType, DrawableGameObject* const object)
{
	mLayers[layerType].addObjectToDrawables(object);

	WE_CORE_INFO("\"" + object->getName() + "\" was added to " + getLayerName(layerType));
}

void StateRenderer::removeObjectFromDrawables(LayerType layerType, DrawableGameObject* const object)
{
	mLayers[layerType].removeObjectFromDrawables(object);

	WE_CORE_INFO("\"" + object->getName() + "\" was removed from " + getLayerName(layerType));
}

void StateRenderer::removeObjectFromDrawables(LayerType layerType, const std::string& objectName)
{
	mLayers[layerType].removeObjectFromDrawables(objectName);

	WE_CORE_INFO("\"" + objectName + "\" was removed from " + getLayerName(layerType));
}

void StateRenderer::removeObjectFromDrawables(const std::string& objectName)
{
	for (auto& layer : mLayers)
		layer.second.removeObjectFromDrawables(objectName);

	WE_CORE_INFO("\"" + objectName + "\" was removed from layers it existed in");
}

void StateRenderer::clearDrawables(LayerType layerType)
{
	mLayers[layerType].clearDrawables();

	WE_CORE_INFO("Drawable objects were removed from " + getLayerName(layerType));
}

void StateRenderer::clearDrawables()
{
	for (auto& layer : mLayers)
		layer.second.clearDrawables();

	WE_CORE_INFO("Drawable objects were removed from all layers");
}

std::string StateRenderer::getLayerName(LayerType layerType)
{
	return mLayerNames[layerType];
}

}