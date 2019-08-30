#include "Tests/gameState.hpp"
#include "sharedData.hpp"

namespace WhitE {

GameState::GameState(SharedData& sharedData, const sf::Vector2f& viewSize)
	:BaseState(sharedData)
{
	getSharedData().mRenderer.getCamera().setViewSize(viewSize);
}

void GameState::onPop()
{
	mStateRenderer.clearDrawables();
	getSharedData().mRenderer.getCamera().resetCameraTarget();
	WE_INFO("Game State popped from the stack");
}
void GameState::onPush()
{
	getRoot().addChild(std::make_unique<Background>(mStateRenderer, getSharedData()));
	getRoot().addChild(std::make_unique<Player>(mStateRenderer, getSharedData()));

	getSharedData().mRenderer.getCamera().setCameraTarget(dynamic_cast<DrawableGameObject*>(&getRoot().getChild("Player")));

	WE_CORE_INFO("Game State pushed on the stack");
}

void GameState::draw() const
{
	mStateRenderer.draw();
}

void GameState::input()
{
	getRoot().inputObjects();
}
void GameState::update(const sf::Time& deltaTime)
{
	getRoot().updateObjects(deltaTime);
}

}