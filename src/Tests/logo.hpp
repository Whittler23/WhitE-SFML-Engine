#pragma once

#include "Objects/drawableGameObject.hpp"
#include "sharedData.hpp"

namespace WhitE {

class LogoSplash : public DrawableGameObject
{
public:
	LogoSplash(SharedData& sharedData)
		:DrawableGameObject(sharedData, LayerType::StaticObjects, "LogoSplash")
	{
		loadResources();
		init();
	}

	~LogoSplash()
	{
	}

	void loadResources()
	{
		getSharedData().mResourcesHolder.getTextureHolder().load("testLogo", "resources/textures/testLogo.png");
	}

	void init()
	{
		auto windowSize = getSharedData().mWindow.getRenderWindow().getSize();
		mText.setPosition(40.f, 50.f);
		mText.setFont(getSharedData().mResourcesHolder.getFontHolder().get("testFont"));
		mText.setString("Welcome to WhitE!");
		mText.setCharacterSize(64);

		mLogoSprite.setTexture(getSharedData().mResourcesHolder.getTextureHolder().get("testLogo"));
		mLogoSprite.setScale(0.333f, 0.333f);
		mLogoSprite.setPosition(0.f, 150.f);
	}

	void draw(sf::RenderTarget& rt, sf::RenderStates rs) const override
	{
		rt.draw(mLogoSprite);
		rt.draw(mText);
	}

private:
	sf::Sprite mLogoSprite;
	sf::Text mText;
};

}