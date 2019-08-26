#pragma once

#include "window.hpp"
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
	~GameEngine();

	void start();

	void initState(std::unique_ptr<BaseState> initState);
	void initGlobalActions(std::vector<std::pair<std::string, sf::Keyboard::Key>>);

	auto getWindow() -> Window & { return mGameWindow; }
	auto getRenderWindow() -> sf::RenderWindow & { return mGameWindow.getRenderWindow(); }
	auto getDataCollector() -> DataCollector & { return mDataCollector; }
	auto getResourcesHolder() -> ResourcesHolder & { return mResourcesHolder; }
	auto getStatesManager() -> StatesManager & { return mStatesManager; }
	auto getRenderer() -> Renderer & { return mRenderer; }
	auto getSharedData() -> SharedData & { return mSharedData; }

private:
	void update(const sf::Time deltaTime);
	void input();
	void draw();

	void initializeRenderer();

private:
	Window mGameWindow;
	ResourcesHolder mResourcesHolder;
	Renderer mRenderer;
	SharedData mSharedData;
	DataCollector mDataCollector;
	StatesManager mStatesManager;

};

}