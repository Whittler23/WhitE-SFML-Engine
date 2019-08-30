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

void DrawableGameObject::setPosition(const sf::Vector2f& position)
{
	mPosition = position;
	mSprite.setPosition(mPosition);
}

void DrawableGameObject::setScale(const sf::Vector2f& scale)
{
	mScale = scale;
	mSprite.setScale(mScale);
}

void DrawableGameObject::setRotation(const float rotationAngle)
{
	mRotation = rotationAngle;
	mSprite.setRotation(mRotation);
}

void DrawableGameObject::setVisibility(const bool visibility)
{
	mVisibility = visibility;
}

void DrawableGameObject::rotate(const float angle)
{
	mRotation += angle;
	mSprite.setRotation(mRotation);
}

sf::Vector2f DrawableGameObject::getPosition() const
{
	return mPosition;
}

sf::Vector2f DrawableGameObject::getScale() const
{
	return mScale;
}

float DrawableGameObject::getRotation() const
{
	return mRotation;
}

bool DrawableGameObject::getVisibility() const
{
	return mVisibility;
}

auto DrawableGameObject::getSharedData() -> SharedData &
{
	return mSharedData;
}

}