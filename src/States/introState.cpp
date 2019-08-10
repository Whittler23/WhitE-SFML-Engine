#include "States/IntroState.hpp"
#include "Logger/logs.hpp"
#include "Resources/resourcesHolder.hpp"

namespace WhitE {

	IntroState::IntroState(sf::RenderWindow& win, ResourceHolder& rh)
		: mRenderTarget(win)
		, mResources(rh)
{
		onPush();
}

IntroState::~IntroState()
{

}

void IntroState::onPush() 
{
	mResources.getTextureHolder().load("resources/textures/testLogo.png");
	mSplash.setPosition(mRenderTarget.getSize().x / 2.f, mRenderTarget.getSize().y / 2.f);
	mSplash.setTexture(mResources.getTextureHolder().get("resources/textures/testLogo.png"));
	mSplash.setScale(0.15, 0.15f);
}

void IntroState::onPop()
{
	mResources.getTextureHolder().free("resources/textures/testLogo.png");
}

void IntroState::draw() const
{
	mRenderTarget.draw(mSplash);
}

void  IntroState::update(const sf::Time& deltaTime)
{

}

}