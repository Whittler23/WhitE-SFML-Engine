#include "Objects/drawableGameObject.hpp"
#include "Renderer/stateRenderer.hpp"

namespace WhitE {

DrawableGameObject::DrawableGameObject(StateRenderer& stateRenderer, SharedData& sharedData, LayerType layerType, const std::string& name)
	:GameObject(name)
	,mSharedData(sharedData)
	,mVisibility(true)
	,mRotation(0.f)
	,mScale(0.f, 0.f)
	,mPosition(0.f, 0.f)
{
	stateRenderer.addObjectToDrawables(layerType, this);
}

void DrawableGameObject::setPosition(sf::Vector2f& position)
{
	mPosition = position;
}

sf::Vector2f DrawableGameObject::getPosition() const
{
	return mPosition;
}

}