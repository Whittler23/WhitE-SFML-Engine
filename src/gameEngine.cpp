#include "gameEngine.hpp"
#include "States/BaseState.hpp"
#include "States/IntroState.hpp"

namespace WhitE {

GameEngine::GameEngine()
	:mGameWindow()
	,mDataCollector(getWindow())
{
	mStates.push(new IntroState(getWindow(), getResourceHolder()));
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
}

void GameEngine::update(const sf::Time deltaTime)
{
	if (!mStates.empty()) mStates.top()->update(deltaTime);
	mDataCollector.update(deltaTime);
	mGameWindow.update();
}

void GameEngine::draw()
{
	mGameWindow.getRenderWindow().clear();

	if(!mStates.empty()) mStates.top()->draw();
	mGameWindow.getRenderWindow().draw(mDataCollector.getDebuggerDisplayer().getText());

	mGameWindow.getRenderWindow().display();
}

}