#pragma once

#include "sharedData.hpp"

namespace WhitE {

class Background : public Entity
{
public:
	Background(SharedData& sharedData, const std::string& backgroundName)
		:Entity(sharedData, "Background")
	{
		init(backgroundName);
	}

	void init(const std::string& backgroundName)
	{
		mSprite.setTexture(getSharedData().mResourcesHolder.getTextureHolder().get(backgroundName));	
	}

	void draw(sf::RenderTarget& rt, sf::RenderStates rs) const override
	{
		rt.draw(mSprite);
	}

private:
	sf::Sprite mSprite;
};

}