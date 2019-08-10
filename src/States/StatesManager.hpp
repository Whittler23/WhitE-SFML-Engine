#pragma once

#include <SFML/Graphics.hpp>

#include <stack>

namespace WhitE {

class BaseState;
class ResourceHolder;
class Window;

class StatesManager
{
public:
	StatesManager(Window& window, ResourceHolder& resourcesHolder);
	~StatesManager();

	void update(const sf::Time& deltaTime);
	void draw();
	void input();

	void pushScene(std::unique_ptr<BaseState> state);
	void popScene();

	auto getResources() const -> ResourceHolder & { return mResources; }
	auto getWindow() const -> Window & { return mWindow; }

private:
	Window& mWindow;
	ResourceHolder& mResources;
	std::stack<std::unique_ptr<BaseState>> mStack;
};

}