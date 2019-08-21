#include "States/IntroState.hpp"
#include "Logger/logs.hpp"
#include "Resources/resourcesHolder.hpp"
#include "States/StatesManager.hpp"
#include "sharedData.hpp"
#include "States/baseState.hpp"
#include "Input/actionManager.hpp"
#include "Objects/gameObject.hpp"

namespace WhitE {

IntroState::IntroState(SharedData& sharedData)
	:mSharedData(sharedData)
{
	onPush();
}

IntroState::~IntroState()
{
	onPop();
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
	mSplash.setScale(0.15, 0.15);

	mText.setFont(getSharedData().mResourcesHolder.getFontHolder().get("resources/fonts/testFont.ttf"));
	mText.setPosition(mSplash.getPosition().x, mSplash.getPosition().y - 50.f);
	mText.setString("Press \"Space\" to continue!");

	ActionManager::addAction("Continue", sf::Keyboard::Space);
}

void IntroState::onPop()
{
	getSharedData().mResourcesHolder.getTextureHolder().free("resources/textures/testLogo.png");
	getSharedData().mResourcesHolder.getFontHolder().free("resources/fonts/testFont.ttf");
	ActionManager::deleteAction("Continue");

	WE_INFO("InfoState popped from the stack");
}

void IntroState::draw() const
{
	getSharedData().mWindow.getRenderWindow().draw(mSplash);

	if (getTime() > 5)
	{
		getSharedData().mWindow.getRenderWindow().draw(mText);
	}
}

void IntroState::input()
{
	if (ActionManager::isActionPressed("Continue"))
		setShouldPop(true);

	getRoot().input();

}

void IntroState::update(const sf::Time& deltaTime)
{
	getRoot().update(deltaTime);
}

}