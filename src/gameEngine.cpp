#include "gameEngine.hpp"
#include "States/BaseState.hpp"
#include "States/IntroState.hpp"

namespace WhitE {

GameEngine::GameEngine()
	:mGameWindow()
	,mDataCollector(getRenderWindow())
	,mStatesManager(mGameWindow, mResourcesHolder)
	,mSharedData(getWindow(), getResourcesHolder(), getStatesManager())
{
	mStatesManager.pushScene(std::make_unique<IntroState>(getSharedData()));
}

void GameEngine::start()
{
	sf::Clock gameClock;
	sf::Time timeSinceLastTick = sf::Time::Zero;
	const sf::Time frameTime = sf::seconds(1.f / 60.f);

	while (mGameWindow.isOpen())	
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

void GameEngine::input()
{
	mStatesManager.input();
}

void GameEngine::update(const sf::Time deltaTime)
{
	mStatesManager.update(deltaTime);
	mDataCollector.update(deltaTime);
	mGameWindow.update();
}

void GameEngine::draw()
{
	mGameWindow.getRenderWindow().clear();

	mStatesManager.draw();
	getRenderWindow().draw(mDataCollector.getDebuggerDisplayer().getText());

	mGameWindow.getRenderWindow().display();
}

}