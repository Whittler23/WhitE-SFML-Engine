#pragma once

#include "Debugger/debuggerDisplayer.hpp"

#include <SFML/System.hpp>

namespace WhitE {

class DataCollector
{
public:
	DataCollector(Renderer& renderer);

	void update(const sf::Time deltaTime);
	void input();

	auto getDebuggerDisplayer() -> DebuggerDisplayer& { return mDebuggerDisplayer; }

private:
	DebuggerDisplayer mDebuggerDisplayer;
	sf::Clock mOneSecondClock;
	int mFramesPerSecond;

};

}
