#pragma once

#include "Window/window.hpp"

#include <SFML/Graphics.hpp>

namespace WhitE {

class GameEngine
{
public:
	GameEngine();

	void start();

	auto getWindow() const -> const Window & { return mGameWindow; }

private:
	void update(const sf::Time deltaTime);
	void draw();
	void input();

private:
	Window mGameWindow;

};

}