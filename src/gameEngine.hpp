#pragma once

#include "Window/window.hpp"
#include "Debugger/dataCollector.hpp"
#include "Resources/ResourcesHolder.hpp"
#include "States/StatesManager.hpp"
#include "sharedData.hpp"

#include <SFML/Graphics.hpp>

#include <stack>

namespace WhitE {

class BaseState;

class GameEngine
{
public:
	GameEngine();

	void start();

	auto getWindow() -> Window & { return mGameWindow; }
	auto getRenderWindow() -> sf::RenderWindow & { return mGameWindow.getRenderWindow(); }
	auto getResourceHolder() -> ResourceHolder & { return mResourceHolder; }
	auto getStatesManager() -> StatesManager & { return mStatesManager; }
	auto getSharedData() -> SharedData & { return mSharedData; }

private:
	void update(const sf::Time deltaTime);
	void draw();
	void input();

private:
	Window mGameWindow;
	DataCollector mDataCollector;
	ResourceHolder mResourceHolder;
	StatesManager mStatesManager;
	SharedData mSharedData;

};

}