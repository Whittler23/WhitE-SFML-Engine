#pragma once

#include "Window/window.hpp"
#include "Debugger/dataCollector.hpp"
#include "Resources/ResourcesHolder.hpp"
#include "States/StatesManager.hpp"
#include "Renderer/renderer.hpp"
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
	auto getDataCollector() -> DataCollector & { return mDataCollector; }
	auto getRenderWindow() -> sf::RenderWindow & { return mGameWindow.getRenderWindow(); }
	auto getResourcesHolder() -> ResourcesHolder & { return mResourcesHolder; }
	auto getStatesManager() -> StatesManager & { return mStatesManager; }
	auto getSharedData() -> SharedData & { return mSharedData; }

private:
	void update(const sf::Time deltaTime);
	void input();
	void draw();

	void initializeRenderer();
	void initializeEngineActions();

private:
	Window mGameWindow;
	DataCollector mDataCollector;
	ResourcesHolder mResourcesHolder;
	StatesManager mStatesManager;
	Renderer mRenderer;
	SharedData mSharedData;

};

}