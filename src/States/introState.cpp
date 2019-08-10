#include "States/IntroState.hpp"
#include "Logger/logs.hpp"
#include "Resources/resourcesHolder.hpp"
#include "States/StatesManager.hpp"
#include "sharedData.hpp"
#include "States/baseState.hpp"
#include "Input/actionManager.hpp"

namespace WhitE {

IntroState::IntroState(SharedData& sharedData)
	:mSharedData(sharedData)
	,mContinue(false)
{
	onPush();
}

IntroState::~IntroState()
{

}

void IntroState::onPush() 
{
	getSharedData().mResourceHolder.getTextureHolder().load("resources/textures/testLogo.png");
	getSharedData().mResourceHolder.getFontHolder().load("resources/fonts/testFont.ttf");

	mSplash.setPosition(
		getSharedData().mWindow.getRenderWindow().getSize().x / 2.f-300.f, 
		getSharedData().mWindow.getRenderWindow().getSize().y / 2.f
	);
	mSplash.setTexture(getSharedData().mResourceHolder.getTextureHolder().get("resources/textures/testLogo.png"));
	mSplash.setScale(0.15, 0.15);

	mText.setFont(getSharedData().mResourceHolder.getFontHolder().get("resources/fonts/testFont.ttf"));
	mText.setPosition(mSplash.getPosition().x, mSplash.getPosition().y - 50.f);
	mText.setString("Press \"Space\" to continue!");

	ActionManager::addAction("Continue", sf::Keyboard::Space);
}

void IntroState::onPop()
{
	getSharedData().mResourceHolder.getTextureHolder().free("resources / textures / testLogo.png");
	getSharedData().mResourceHolder.getTextureHolder().free("resources / fonts / testFont.ttf");
}

void IntroState::draw() const
{
	getSharedData().mWindow.getRenderWindow().draw(mSplash);

	if(getTime() > 5)
		getSharedData().mWindow.getRenderWindow().draw(mText);
}

void IntroState::input()
{
	if (ActionManager::isActionPressed("Continue"))
		mContinue = true;
}

void IntroState::update(const sf::Time& deltaTime)
{
	if (shouldContinue())
		getSharedData().mStatesManager.popScene();
}

}