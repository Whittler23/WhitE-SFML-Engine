#include "Objects/entity.hpp"
#include "Logger/logs.hpp"

namespace WhitE {

Entity::Entity(SharedData& sharedData, const std::string& name)
	:mName(name)
	,mSharedData(sharedData)
	,mVisibility(true)
	,mRotation(0.f)
	,mScale(0.f, 0.f)
	,mPosition(0.f, 0.f)
{
}

void Entity::update(const sf::Time& deltaTime)
{
}

void Entity::input()
{
}

void Entity::setPosition(const sf::Vector2f& position)
{
	mPosition = position;
	mSprite.setPosition(mPosition);
}

void Entity::setScale(const sf::Vector2f& scale)
{
	mScale = scale;
	mSprite.setScale(mScale);
}

void Entity::setRotation(const float rotationAngle)
{
	mRotation = rotationAngle;
	mSprite.setRotation(mRotation);
}

void Entity::setVisibility(const bool visibility)
{
	mVisibility = visibility;
}

void Entity::rotate(const float angle)
{
	mRotation += angle;
	mSprite.setRotation(mRotation);
}

sf::Vector2f Entity::getPosition() const
{
	return mPosition;
}

sf::Vector2f Entity::getScale() const
{
	return mScale;
}

float Entity::getRotation() const
{
	return mRotation;
}

bool Entity::getVisibility() const
{
	return mVisibility;
}

auto Entity::getSharedData() -> SharedData &
{
	return mSharedData;
}

}