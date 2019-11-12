#pragma once

#include "window.hpp"
#include "Resources/ResourcesHolder.hpp"
#include "States/StatesManager.hpp"
#include "Renderer/camera.hpp"
#include "sharedData.hpp"

#include <SFML/Graphics.hpp>

#include <stack>

namespace WhitE {

class State;

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void start();

	void initState(std::unique_ptr<State> initState);
	void initGlobalActions(std::vector<std::pair<std::string, sf::Keyboard::Key>>);
	void initGameFonts(std::vector<std::pair<std::string, std::string>>);

	auto getWindow() -> Window & { return mGameWindow; }
	auto getRenderWindow() -> sf::RenderWindow & { return mGameWindow.getRenderWindow(); }
	auto getResourcesHolder() -> ResourcesHolder & { return mResourcesHolder; }
	auto getStatesManager() -> StatesManager & { return mStatesManager; }
	auto getSharedData() -> SharedData & { return mSharedData; }

private:
	void update(const sf::Time deltaTime);
	void input();
	void draw();

	void initializeRenderer();

private:
	Window mGameWindow;
	ResourcesHolder mResourcesHolder;
	Camera mCamera;
	SharedData mSharedData;
	StatesManager mStatesManager;

};

}