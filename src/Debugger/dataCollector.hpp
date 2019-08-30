#pragma once

#include "Debugger/debuggerDisplayer.hpp"

#include <SFML/System.hpp>

namespace WhitE {

class ResourcesHolder;

class DataCollector
{
public:
	DataCollector(Renderer& renderer);

	void init(ResourcesHolder& resourcesHolder);

	void update(const sf::Time deltaTime);
	void input();

	auto getDebuggerDisplayer() -> DebuggerDisplayer& { return mDebuggerDisplayer; }

private:
	DebuggerDisplayer mDebuggerDisplayer;
	sf::Clock mOneSecondClock;
	int mFramesPerSecond;

};

}
