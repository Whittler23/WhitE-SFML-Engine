#include "Tests/gameState.hpp"
#include "Gui/GuiElements/button.hpp"
#include "Objects/drawableGameObject.hpp"
#include "sharedData.hpp"
#include "Utilities/cast.hpp"

namespace WhitE {

GameState::GameState(SharedData& sharedData, const sf::Vector2f& viewSize)
	:BaseState(sharedData)
{
	getSharedData().mCamera.setViewSize(viewSize);
}

void GameState::onPop()
{
	getSharedData().mCamera.resetCameraTarget();
	WE_INFO("Game State popped from the stack");
}
void GameState::onPush()
{
	mEntities.emplace_back(std::make_unique<Background>(getSharedData()));
	mEntities.emplace_back(std::make_unique<Player>(getSharedData()));

	for (auto& entity : mEntities)
	{
		if (entity->getName() == "Player")
			getSharedData().mCamera.setCameraTarget(dynamic_cast<DrawableGameObject*>(&*entity));
	}


	WE_INFO("Game State pushed on the stack");
}

void GameState::draw() const
{
	for (auto& entity : mEntities)
		getRenderTarget().draw(*entity);
		
	mStateGuiManager.drawGuiSets();
}

void GameState::input()
{
	for (auto& entity : mEntities)
		entity->input();

	mStateGuiManager.inputGuiSets();
}

void GameState::update(const sf::Time & deltaTime)
{
	for (auto& entity : mEntities)
		entity->update(deltaTime);

	mStateGuiManager.updateGuiSets(deltaTime);
}

}