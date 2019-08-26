#include "gameEngine.hpp"
#include "States/BaseState.hpp"
#include "States/IntroState.hpp"
#include "Input/actionManager.hpp"
#include "States/gameState.hpp"

namespace WhitE {

GameEngine::GameEngine()
	:mGameWindow()
	,mDataCollector(getRenderer())
	,mStatesManager(mGameWindow, mResourcesHolder)
	,mRenderer(mGameWindow.getRenderWindow())
	,mSharedData(getWindow(), getResourcesHolder(), getRenderer())
{
	initializeRenderer();
	initializeEngineActions();
}

GameEngine::~GameEngine()
{

}

void GameEngine::initializeRenderer()
{
}

void GameEngine::initializeEngineActions()
{
	ActionManager::addAction("SwitchDebugger", sf::Keyboard::Tab);
	ActionManager::addAction("PopState", sf::Keyboard::BackSpace);
	ActionManager::addAction("PushGame", sf::Keyboard::G);
	ActionManager::addAction("PushIntro", sf::Keyboard::I);
}

void GameEngine::setInitState(std::unique_ptr<BaseState> initState)
{
	mStatesManager.pushState(std::move(initState));
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
		getStatesManager().pushState(std::make_unique<GameState>(getSharedData()));
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