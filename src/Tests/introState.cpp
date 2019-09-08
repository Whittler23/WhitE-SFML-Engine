#include "Logger/logs.hpp"
#include "Resources/resourcesHolder.hpp"
#include "States/StatesManager.hpp"
#include "sharedData.hpp"
#include "States/baseState.hpp"
#include "Input/actionManager.hpp"
#include "Input/mouseManager.hpp"
#include "Objects/drawableGameObject.hpp"
#include "Renderer/renderer.hpp"
#include "Objects/entity.hpp"

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
	mEntities.emplace_back(std::make_unique<LogoSplash>(getSharedData()));

	mStateGuiManager.addGuiButton(std::make_unique<Button>(getSharedData(), sf::Vector2f(30, 15), sf::Vector2f(40, 15), "PLAY"));
	mStateGuiManager.addGuiButton(std::make_unique<Button>(getSharedData(), sf::Vector2f(30, 35), sf::Vector2f(40, 15), "SETTINGS"));
	mStateGuiManager.addGuiButton(std::make_unique<Button>(getSharedData(), sf::Vector2f(30, 55), sf::Vector2f(40, 15), "CREDITS"));
	mStateGuiManager.addGuiButton(std::make_unique<Button>(getSharedData(), sf::Vector2f(30, 75), sf::Vector2f(40, 15), "EXIT"));

	WE_INFO("Intro State pushed on the stack"); 
}

void IntroState::onPop()
{
	getSharedData().mResourcesHolder.getTextureHolder().free("testLogo");
	getSharedData().mResourcesHolder.getFontHolder().free("testFont");

	ActionManager::deleteAction("Continue");
	ActionManager::deleteAction("Move");

	WE_INFO("Intro State popped from the stack");
}

void IntroState::draw() const
{
	for (auto& entity : mEntities)
		getRenderTarget().draw(*entity);

	mStateGuiManager.drawGuiElements();
}

void IntroState::input()
{
	for (auto& entity : mEntities)
		entity->input();

	mStateGuiManager.inputGuiElements();
}

void IntroState::update(const sf::Time& deltaTime)
{
	for (auto& entity : mEntities)
		entity->update(deltaTime);

	mStateGuiManager.updateGuiElements(deltaTime);
}

}