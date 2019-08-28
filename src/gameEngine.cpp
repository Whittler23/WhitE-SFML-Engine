#include "gameEngine.hpp"
#include "States/BaseState.hpp"
#include "Input/actionManager.hpp"

#include "Tests/IntroState.hpp"
#include "Tests/gameState.hpp"

namespace WhitE {

GameEngine::GameEngine()
	:mGameWindow()
	,mDataCollector(getRenderer())
	,mStatesManager(mGameWindow, mResourcesHolder)
	,mRenderer(mGameWindow.getRenderWindow())
	,mSharedData(getWindow(), getResourcesHolder(), getRenderer())
{
	initializeRenderer();
}

GameEngine::~GameEngine()
{

}

void GameEngine::initializeRenderer()
{
}

void GameEngine::initState(std::unique_ptr<BaseState> initState)
{
	mStatesManager.pushState(std::move(initState));
}

void GameEngine::initGlobalActions(std::vector<std::pair<std::string, sf::Keyboard::Key>> actions)
{
	for (auto& action : actions)
		ActionManager::addAction(action.first, action.second);
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
	mRenderer.update(deltaTime);
	mStatesManager.update(deltaTime);
	mDataCollector.update(deltaTime);
	mGameWindow.updateEvents();
	mGameWindow.update();
}

void GameEngine::input()
{
	mStatesManager.input();
	mDataCollector.input();
	mGameWindow.input();

	if (ActionManager::isActionPressed("PopState"))
		getStatesManager().popState();
	if(ActionManager::isActionPressed("PushGame"))
		getStatesManager().pushState(std::make_unique<GameState>(getSharedData(), sf::Vector2f(500, 500)));
	if (ActionManager::isActionPressed("PushIntro"))
		getStatesManager().pushState(std::make_unique<IntroState>(getSharedData()));
}

void GameEngine::draw()
{
	mGameWindow.getRenderWindow().clear();

	mRenderer.draw();
	mStatesManager.draw();

	mGameWindow.getRenderWindow().display();
}

}