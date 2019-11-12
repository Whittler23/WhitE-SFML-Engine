#pragma once

#include <SFML/Graphics.hpp>

#include <stack>

namespace WhitE {

class State;
class ResourcesHolder;
class Window;

class StatesManager
{
public:
	StatesManager(Window& window, ResourcesHolder& resourcesHolder);
	~StatesManager();

	void update(const sf::Time& deltaTime);
	void draw();
	void input();

	void pushState(std::unique_ptr<State> state);
	void popState();

	auto getResources() const -> ResourcesHolder & { return mResources; }
	auto getWindow() const -> Window & { return mWindow; }
	bool isEmpty();

private:
	Window& mWindow;
	ResourcesHolder& mResources;
	std::stack<std::unique_ptr<State>> mStack;
};

}