#pragma once

namespace WhitE {

class LogoSplash : public DrawableGameObject
{
public:
	LogoSplash(StateRenderer& stateRenderer, SharedData& sharedData)
		:DrawableGameObject(stateRenderer , sharedData, LayerType::StaticObjects, "LogoSplash")
	{
		loadResources();
		init();
	}

	~LogoSplash()
	{
		getSharedData().mResourcesHolder.getTextureHolder().free("resources/textures/testLogo.png");
	}

	void loadResources()
	{
		getSharedData().mResourcesHolder.getFontHolder().load("resources/fonts/testFont.ttf");
		getSharedData().mResourcesHolder.getTextureHolder().load("resources/textures/testLogo.png");
	}

	void init()
	{
		auto windowSize = getSharedData().mWindow.getRenderWindow().getSize();
		mText.setPosition(40.f, 50.f);
		mText.setFont(getSharedData().mResourcesHolder.getFontHolder().get("resources/fonts/testFont.ttf"));
		mText.setString("Welcome to WhitE!");
		mText.setCharacterSize(64);

		mLogoSprite.setTexture(getSharedData().mResourcesHolder.getTextureHolder().get("resources/textures/testLogo.png"));
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