#include "gameEngine.hpp"

namespace WhitE {

GameEngine::GameEngine()
	:mGameWindow()
	,mDataCollector(getWindow())
{
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
	mDataCollector.update(deltaTime);
	mGameWindow.update();
}

void GameEngine::draw()
{
	
	mGameWindow.draw(mDataCollector.getDebuggerDisplayer().getText());
}

}