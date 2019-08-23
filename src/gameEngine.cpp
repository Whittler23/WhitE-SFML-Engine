#include "gameEngine.hpp"
#include "States/BaseState.hpp"
#include "States/IntroState.hpp"
#include "Input/actionManager.hpp"

#include "Objects/drawableGameObject.hpp"

namespace WhitE {

GameEngine::GameEngine()
	:mGameWindow()
	,mDataCollector(getRenderWindow())
	,mStatesManager(mGameWindow, mResourcesHolder)
	,mRenderer(mGameWindow.getRenderWindow())
	,mSharedData(getWindow(), getResourcesHolder())
{
	initializeRenderer();
	initializeEngineActions();
	mStatesManager.pushState(std::make_unique<IntroState>(getSharedData()));
}

void GameEngine::initializeRenderer()
{
	mRenderer.addObjectToDrawables(&getDataCollector().getDebuggerDisplayer());
}

void GameEngine::initializeEngineActions()
{
	ActionManager::addAction("SwitchDebugger", sf::Keyboard::Tab);
}

void GameEngine::start()
{
	sf::Clock gameClock;
	sf::Time timeSinceLastTick = sf::Time::Zero;
	const sf::Time frameTime = sf::seconds(1.f / 60.f);

	while (!mGameWindow.shouldClose())	
	{
		timeSinceLastTick += gameClock.restart();
		while (timeSinceLastTick > frameTime)
		{
			timeSinceLastTick -= frameTime;
			update(frameTime);
			input();
		}
		draw();
	}
}

void GameEngine::update(const sf::Time deltaTime)
{
	mStatesManager.update(deltaTime);
	mDataCollector.update(deltaTime);
	mGameWindow.update();
}

void GameEngine::input()
{
	mStatesManager.input();
	mDataCollector.input();
	mGameWindow.input();
}

void GameEngine::draw()
{
	mGameWindow.getRenderWindow().clear();

	mRenderer.draw();
	mStatesManager.draw();

	mGameWindow.getRenderWindow().display();
}

}