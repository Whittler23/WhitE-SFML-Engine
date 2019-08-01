#pragma once

#include "Window/window.hpp"
#include "Debugger/dataCollector.hpp"
#include "Resources/resourcesHolder.hpp"

#include <SFML/Graphics.hpp>

namespace WhitE {

class GameEngine
{
public:
	GameEngine();

	void start();

	auto getWindow() -> sf::RenderWindow & { return mGameWindow.getRenderWindow(); }

private:
	void update(const sf::Time deltaTime);
	void draw();
	void input();

private:
	Window mGameWindow;
	DataCollector mDataCollector;
	ResourceHolder mResourceHolder;

};

}