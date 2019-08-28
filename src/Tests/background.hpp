#pragma once

#include "Objects/drawableGameObject.hpp"
#include "sharedData.hpp"

namespace WhitE {

class Background : public DrawableGameObject
{
public:
	Background(StateRenderer& stateRenderer, SharedData& sharedData)
		:DrawableGameObject(stateRenderer, sharedData, LayerType::Background, "Background")
	{
		init();
	}

	void init()
	{
		getSharedData().mResourcesHolder.getTextureHolder().load("resources/textures/Background.png");
		mSprite.setTexture(getSharedData().mResourcesHolder.getTextureHolder().get("resources/textures/Background.png"));
		
	}

	void draw(sf::RenderTarget& rt, sf::RenderStates rs) const override
	{
		rt.draw(mSprite);
	}

private:
	sf::Sprite mSprite;
};

}