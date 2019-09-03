#include "Tests/gameState.hpp"
#include "Gui/GuiElements/button.hpp"
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
	mStateRenderer.clearDrawables();
	mStateRenderer.removeGui();
	getSharedData().mCamera.resetCameraTarget();
	WE_INFO("Game State popped from the stack");
}
void GameState::onPush()
{
	getRoot().addChild(std::make_unique<Background>(mStateRenderer, getSharedData()));
	getRoot().addChild(std::make_unique<Player>(mStateRenderer, getSharedData()));

	getSharedData().mCamera.setCameraTarget(dynamic_cast<DrawableGameObject*>(&getRoot().getChild("Player")));

	WE_INFO("Game State pushed on the stack");
}

void GameState::draw() const
{
	mStateRenderer.draw();
	mStateGuiManager.drawGuiSets();
}

void GameState::input()
{
	getRoot().inputObjects();
	mStateGuiManager.inputGuiSets();
}
void GameState::update(const sf::Time& deltaTime)
{
	getRoot().updateObjects(deltaTime);
	mStateGuiManager.updateGuiSets(deltaTime);
}

}