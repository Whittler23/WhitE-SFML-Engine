#pragma once

#include "sharedData.hpp"

namespace WhitE {

class Background : public Entity
{
public:
	Background(SharedData& sharedData)
		:Entity(sharedData, "Background")
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