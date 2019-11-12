#include "gameEngine.hpp"
#include "States/state.hpp"
#include "Input/actionManager.hpp"

namespace WhitE {

GameEngine::GameEngine()
	:mGameWindow()
	,mStatesManager(mGameWindow, mResourcesHolder)
	,mCamera(mGameWindow.getRenderWindow())
	,mSharedData(mGameWindow, mResourcesHolder, mCamera)
{
	initializeRenderer();
}

GameEngine::~GameEngine()
{

}

void GameEngine::initializeRenderer()
{
}

void GameEngine::initState(std::unique_ptr<State> initState)
{
	mStatesManager.pushState(std::move(initState));
}

void GameEngine::initGlobalActions(std::vector<std::pair<std::string, sf::Keyboard::Key>> actions)
{
	for (auto& action : actions)
		ActionManager::addAction(action.first, action.second);
}

void GameEngine::initGameFonts(std::vector<std::pair<std::string, std::string>> fonts)
{
	for (auto& font : fonts)
		mResourcesHolder.getFontHolder().load(font.first, font.second);
}

void GameEngine::start()
{
	sf::Clock gameClock;
	sf::Time timeSinceLastTick = sf::Time::Zero;
	const sf::Time frameTime = sf::seconds(1.f / 60.f);

	while (!mGameWindow.shouldClose() && !mStatesManager.isEmpty())	
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
	mCamera.update(deltaTime);
	mGameWindow.updateEvents();
}

void GameEngine::input()
{
	mStatesManager.input();
	mGameWindow.input();
}

void GameEngine::draw()
{
	mGameWindow.getRenderWindow().clear();

	mStatesManager.draw();

	mGameWindow.getRenderWindow().display();
}

}