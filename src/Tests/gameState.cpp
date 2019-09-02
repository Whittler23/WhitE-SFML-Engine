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
	mStateGui.addGuiElement(std::make_unique<Button>(getSharedData(), sf::Vector2f(70, 15), sf::Vector2f(25, 15), "TEST"));
	mStateRenderer.attachGui(mStateGui.getStateGuiElements());

	getSharedData().mCamera.setCameraTarget(dynamic_cast<DrawableGameObject*>(&getRoot().getChild("Player")));

	WE_CORE_INFO("Game State pushed on the stack");
}

void GameState::draw() const
{
	mStateRenderer.draw();
}

void GameState::input()
{
	getRoot().inputObjects();
	mStateGui.inputGui();
}
void GameState::update(const sf::Time& deltaTime)
{
	getRoot().updateObjects(deltaTime);
	mStateGui.updateGui(deltaTime);
}

}