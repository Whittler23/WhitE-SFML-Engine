#pragma once

#include "Objects/drawableGameObject.hpp"
#include "sharedData.hpp"

namespace WhitE {

class Background : public DrawableGameObject
{
public:
	Background(SharedData& sharedData)
		:DrawableGameObject(sharedData, LayerType::Background, "Background")
	{
		init();
	}

	void init()
	{
		getSharedData().mResourcesHolder.getTextureHolder().load("background", "resources/textures/Background.png");
		mSprite.setTexture(getSharedData().mResourcesHolder.getTextureHolder().get("background"));
		
	}

	void draw(sf::RenderTarget& rt, sf::RenderStates rs) const override
	{
		rt.draw(mSprite);
	}

private:
	sf::Sprite mSprite;
};

}