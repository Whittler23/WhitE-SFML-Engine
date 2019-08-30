#include "Logger/logs.hpp"
#include "Resources/resourcesHolder.hpp"
#include "States/StatesManager.hpp"
#include "sharedData.hpp"
#include "States/baseState.hpp"
#include "Input/actionManager.hpp"
#include "Input/mouseManager.hpp"
#include "Objects/drawableGameObject.hpp"
#include "Renderer/renderer.hpp"

#include "Tests/IntroState.hpp"
#include "Tests/logo.hpp"
#include "Tests/button.hpp"

namespace WhitE {

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
	getRoot().inputObjects();
}

void IntroState::update(const sf::Time& deltaTime)
{
	getRoot().updateObjects(deltaTime);
}

}