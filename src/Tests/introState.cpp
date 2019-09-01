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
#include "Gui/GuiElements/button.hpp"

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
	mStateGui.addGuiElement(std::make_unique<Button>(getSharedData(), sf::Vector2f(35, 35), sf::Vector2f(30, 30), "EXIT"));
	mStateRenderer.attachGui(mStateGui.getStateGuiElements());

	WE_INFO("Intro State pushed on the stack");
}

void IntroState::onPop()
{
	getSharedData().mResourcesHolder.getTextureHolder().free("testLogo");
	getSharedData().mResourcesHolder.getFontHolder().free("testFont");

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
	mStateGui.inputGui();
}

void IntroState::update(const sf::Time& deltaTime)
{
	getRoot().updateObjects(deltaTime);
	mStateGui.updateGui(deltaTime);
}

}