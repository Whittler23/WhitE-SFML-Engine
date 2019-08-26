#include "States/IntroState.hpp"
#include "Logger/logs.hpp"
#include "Resources/resourcesHolder.hpp"
#include "States/StatesManager.hpp"
#include "sharedData.hpp"
#include "States/baseState.hpp"
#include "Input/actionManager.hpp"
#include "Input/mouseManager.hpp"
#include "Objects/drawableGameObject.hpp"
#include "Renderer/renderer.hpp"

namespace WhitE {

class Button : public DrawableGameObject
{
public:
	Button(StateRenderer& stateRenderer, SharedData& sharedData, const sf::Vector2f& position, const std::string& text)
		:DrawableGameObject(stateRenderer, sharedData, LayerType::StaticObjects, "Button")
		,mButtonText(text, getSharedData().mResourcesHolder.getFontHolder().get("resources/fonts/testFont.ttf"))
		,mPosition(position)
		,mIdleColor(50, 206, 209, 120)
		,mHoverColor(50, 206, 209, 200)
	{
		loadResources();
		init();
	}

	~Button()
	{

	}

	void loadResources()
	{
		getSharedData().mResourcesHolder.getFontHolder().load("resources/fonts/testFont.ttf");
	}

	void init()
	{
		mButtonBackground.setPosition(mPosition);
		mButtonBackground.setSize(sf::Vector2f(160.f, 45.f));
		mButtonBackground.setFillColor(mIdleColor);

		WE_INFO(std::to_string(mButtonBackground.getGlobalBounds().width) + "elo");
		WE_INFO(std::to_string(mButtonText.getGlobalBounds().width) + "elo");

		mButtonText.setCharacterSize(25);
		mButtonText.setPosition(
			mButtonBackground.getPosition().x + mButtonBackground.getSize().x /2 - mButtonText.getGlobalBounds().width/2.f, 
			mButtonBackground.getPosition().y + mButtonBackground.getSize().y / 2 - mButtonText.getGlobalBounds().height/2.f
		);
		mButtonText.move(sf::Vector2f(0, -5.f));
	}

	void input() override
	{
		if (mButtonBackground.getGlobalBounds().contains(sf::Vector2f(MouseManager::getMousePosition())))
			mButtonBackground.setFillColor(mHoverColor);
		else
			mButtonBackground.setFillColor(mIdleColor);
	}

	void draw(sf::RenderTarget& rt, sf::RenderStates) const override
	{
		rt.draw(mButtonBackground);
		rt.draw(mButtonText);
	}


private:
	sf::Color mIdleColor;
	sf::Color mHoverColor;
	sf::RectangleShape mButtonBackground;
	sf::Text mButtonText;
	sf::Vector2f mPosition;
};

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

IntroState::IntroState(SharedData& sharedData)
	:BaseState(sharedData)
{
}

IntroState::~IntroState()
{
}

void IntroState::onPush() 
{
	getRoot().addChild(std::make_unique<LogoSplash>(mStateRenderer, getSharedData()));
	getRoot().addChild(std::make_unique<Button>(mStateRenderer, getSharedData(), sf::Vector2f(50.f, getSharedData().mWindow.getWindowHeight()-80.f), "EXIT"));
	getRoot().addChild(std::make_unique<Button>(mStateRenderer, getSharedData(), sf::Vector2f(250.f, getSharedData().mWindow.getWindowHeight()-80.f), "EXIT"));
	getRoot().addChild(std::make_unique<Button>(mStateRenderer, getSharedData(), sf::Vector2f(450.f, getSharedData().mWindow.getWindowHeight()-80.f), "EXIT"));

	WE_INFO("Intro State pushed on the stack");
}

void IntroState::onPop()
{
	getSharedData().mResourcesHolder.getTextureHolder().free("resources/textures/testLogo.png");
	getSharedData().mResourcesHolder.getFontHolder().free("resources/fonts/testFont.ttf");

	mStateRenderer.clearDrawables();

	ActionManager::deleteAction("Continue");
	ActionManager::deleteAction("Move");

	WE_INFO("Intro State popped from the stack");
}

void IntroState::draw() const
{
	mStateRenderer.draw();
}

void IntroState::input()
{
	getRoot().input();
}

void IntroState::update(const sf::Time& deltaTime)
{
	getRoot().update(deltaTime);
}

}