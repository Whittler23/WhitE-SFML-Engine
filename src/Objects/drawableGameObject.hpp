#pragma once

#include "Objects/entity.hpp"
#include "Renderer/layerType.hpp"

#include <SFML/Graphics.hpp>

namespace WhitE {

class StateRenderer;
struct SharedData;
class ResourcesHolder;

class DrawableGameObject : public Entity, public sf::Drawable
{
public:
	DrawableGameObject(StateRenderer& stateRenderer, SharedData& sharedData, LayerType layerType, const std::string& name);

	sf::Vector2f getPosition() const;
	bool getVisibility() const;

protected:
	virtual void setPosition(const sf::Vector2f& position);
	virtual void setScale(const sf::Vector2f& scale);
	virtual void setRotation(const float rotationAngle);
	virtual void setVisibility(const bool visibility);
	virtual void rotate(const float angle);

	sf::Vector2f getScale() const;
	float getRotation() const;

	auto getSharedData()->SharedData &;

protected:
	sf::Sprite mSprite;

private:
	SharedData& mSharedData;
	sf::Vector2f mPosition;
	sf::Vector2f mScale;
	float mRotation;
	bool mVisibility;
	
};

}