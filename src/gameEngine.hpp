#pragma once

#include "Window/window.hpp"
#include "Debugger/dataCollector.hpp"
#include "Resources/ResourcesHolder.hpp"

#include <SFML/Graphics.hpp>

#include <stack>

namespace WhitE {

class BaseState;

class GameEngine
{
public:
	GameEngine();

	void start();

	auto getWindow() -> sf::RenderWindow & { return mGameWindow.getRenderWindow(); }
	auto getResourceHolder() -> ResourceHolder & { return mResourceHolder; }

private:
	void update(const sf::Time deltaTime);
	void draw();
	void input();

private:
	Window mGameWindow;
	DataCollector mDataCollector;
	ResourceHolder mResourceHolder;

	std::stack<BaseState*> mStates;

};

}