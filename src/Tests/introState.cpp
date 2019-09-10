#include "Logger/logs.hpp"
#include "Resources/resourcesHolder.hpp"
#include "States/StatesManager.hpp"
#include "sharedData.hpp"
#include "States/baseState.hpp"
#include "Tests/gameState.hpp"
#include "Input/actionManager.hpp"
#include "Input/mouseManager.hpp"
#include "Renderer/renderer.hpp"
#include "Objects/entity.hpp"
#include "Tests/background.hpp"

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
	mStateGuiManager.addGuiButton("Play", std::make_unique<Button>(
		getSharedData(),sf::Vector2f(7, 10), sf::Vector2f(30, 15),"PLAY"
		, sf::Color(0, 0, 0, 50), sf::Color(0, 0, 0, 150), sf::Color::Blue, 2.f));
	mStateGuiManager.addGuiButton("Settings", std::make_unique<Button>(
		getSharedData(), sf::Vector2f(10, 30), sf::Vector2f(30, 15), "SETTINGS"
		, sf::Color(0, 0, 0, 50), sf::Color(0, 0, 0,150), sf::Color::Blue, 2.f));
	mStateGuiManager.addGuiButton("Credits", std::make_unique<Button>(
		getSharedData(), sf::Vector2f(13, 50), sf::Vector2f(30, 15), "CREDITS"
		, sf::Color(0, 0, 0, 50), sf::Color(0, 0, 0, 150), sf::Color::Blue, 2.f));
	mStateGuiManager.addGuiButton("Exit", std::make_unique<Button>(
		getSharedData(), sf::Vector2f(16, 70), sf::Vector2f(30, 15), "EXIT"
		, sf::Color(0, 0, 0, 50), sf::Color(0, 0, 0, 150), sf::Color::Blue, 2.f));

	getSharedData().getTextures().load("backgroundIntro", "resources/textures/backgroundIntro.jpg");
	mEntities.emplace_back(std::make_unique<Background>(getSharedData(), std::string("backgroundIntro")));

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
		setNextState(std::make_unique<GameState>(getSharedData(), sf::Vector2f(500.f, 500.f)));
	else if (buttons["Settings"]->isPressed())
		return;
	else if (buttons["Exit"]->isPressed())
		setShouldPop(true);
	
}

}