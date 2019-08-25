#include "States/IntroState.hpp"
#include "Logger/logs.hpp"
#include "Resources/resourcesHolder.hpp"
#include "States/StatesManager.hpp"
#include "sharedData.hpp"
#include "States/baseState.hpp"
#include "Input/actionManager.hpp"
#include "Input/mouseManager.hpp"
#include "Objects/gameObject.hpp"
#include "Renderer/renderer.hpp"

namespace WhitE {

IntroState::IntroState(SharedData& sharedData)
	:BaseState(sharedData)
	,mShouldDraw(false)
{
}

IntroState::~IntroState()
{
}

void IntroState::onPush() 
{
	getSharedData().mResourcesHolder.getTextureHolder().load("resources/textures/testLogo.png");
	getSharedData().mResourcesHolder.getFontHolder().load("resources/fonts/testFont.ttf");

	mSplash.setPosition(
		getSharedData().mWindow.getRenderWindow().getSize().x / 2.f-300.f, 
		getSharedData().mWindow.getRenderWindow().getSize().y / 2.f
	);
	mSplash.setTexture(getSharedData().mResourcesHolder.getTextureHolder().get("resources/textures/testLogo.png"));
	mSplash.setScale(.15f, .15f);

	mText.setFont(getSharedData().mResourcesHolder.getFontHolder().get("resources/fonts/testFont.ttf"));
	mText.setPosition(mSplash.getPosition().x, mSplash.getPosition().y - 50.f);
	mText.setString("Press \"Space\" to continue!");

	ActionManager::addAction("Continue", sf::Keyboard::Space);
	ActionManager::addAction("Move", sf::Keyboard::D);

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
	getSharedData().mWindow.getRenderWindow().draw(mSplash);

	if (mShouldDraw)
	{
		getSharedData().mWindow.getRenderWindow().draw(mText);
	}
}

void IntroState::input()
{
	if (ActionManager::isActionPressed("Continue"))
		setShouldPop(true);
	if (ActionManager::isActionPressed("Move"))
		mText.setPosition(mText.getPosition() + sf::Vector2f(50.f, 20.f));
	mShouldDraw = (MouseManager::getLastMouseClickPosition().x > 100 ? true : false);

	getRoot().input();
}

void IntroState::update(const sf::Time& deltaTime)
{
	getRoot().update(deltaTime);
}

}