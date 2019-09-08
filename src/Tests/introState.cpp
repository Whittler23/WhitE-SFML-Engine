#include "Logger/logs.hpp"
#include "Resources/resourcesHolder.hpp"
#include "States/StatesManager.hpp"
#include "sharedData.hpp"
#include "States/baseState.hpp"
#include "Input/actionManager.hpp"
#include "Input/mouseManager.hpp"
#include "Renderer/renderer.hpp"
#include "Objects/entity.hpp"

#include "Tests/IntroState.hpp"
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
	mStateGuiManager.addGuiButton(std::make_pair("Play", std::make_unique<Button>(getSharedData(),sf::Vector2f(30, 15), sf::Vector2f(40, 15), "PLAY")));
	mStateGuiManager.addGuiButton(std::make_pair("Settings", std::make_unique<Button>(getSharedData(),sf::Vector2f(30, 35), sf::Vector2f(40, 15), "SETTINGS")));
	mStateGuiManager.addGuiButton(std::make_pair("Credits", std::make_unique<Button>(getSharedData(),sf::Vector2f(30, 55), sf::Vector2f(40, 15), "CREDITS")));
	mStateGuiManager.addGuiButton(std::make_pair("Exit", std::make_unique<Button>(getSharedData(),sf::Vector2f(30, 75), sf::Vector2f(40, 15), "EXIT")));

	WE_INFO("Intro State pushed on the stack"); 
}

void IntroState::onPop()
{
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
	updateButtonsActions(deltaTime);
}

void IntroState::updateButtonsActions(const sf::Time& deltaTime)
{
	auto& buttons = mStateGuiManager.getGuiButtons();
	if (buttons["Play"]->isPressed())
		return;
	else if (buttons["Settings"]->isPressed())

		return;
	else if (buttons["Exit"]->isPressed())
		setShouldPop(true);
	
}

}