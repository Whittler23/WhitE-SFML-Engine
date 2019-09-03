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
#include "Tests/GuiSets/mainMenuSet.hpp"
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

	mStateGuiManager.addGuiSet(std::make_unique<MainMenuButtonsSet>(getSharedData()));

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
	mStateGuiManager.drawGuiSets();
}

void IntroState::input()
{
	getRoot().inputObjects();
	mStateGuiManager.inputGuiSets();
}

void IntroState::update(const sf::Time& deltaTime)
{
	getRoot().updateObjects(deltaTime);
	mStateGuiManager.updateGuiSets(deltaTime);
}

}