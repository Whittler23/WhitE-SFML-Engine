#pragma once

#include "Objects/gameObject.hpp"
#include "Renderer/layerType.hpp"

#include <SFML/Graphics.hpp>

namespace WhitE {

class StateRenderer;
class ResourcesHolder;

class DrawableGameObject : public GameObject, public sf::Drawable
{
public:
	DrawableGameObject(StateRenderer& stateRenderer, ResourcesHolder& resourcesHolder, LayerType layerType, const std::string& name);

	sf::Vector2f getPosition() const;
	sf::Vector2f getScale() const;
	float getRotation() const;
	bool getVisibility() const;

	void setPosition(sf::Vector2f& position);
	void setScale(sf::Vector2f& scale);
	void setRotation(float rotation);
	void setVisibility(bool visibility);
	void rotate(float rotation);

private:
	ResourcesHolder& mResourcesHolder;
	sf::Vector2f mPosition;
	sf::Vector2f mScale;
	float mRotation;
	bool mVisibility;
	
};

}