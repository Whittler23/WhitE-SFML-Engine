#pragma once

#include "Debugger/debuggerDisplayer.hpp"

#include <SFML/System.hpp>

namespace WhitE {

class DataCollector
{
public:
	DataCollector(sf::RenderWindow& renderWindow);

	void update(const sf::Time deltaTime);

	auto getDebuggerDisplayer() -> DebuggerDisplayer& { return mDebuggerDisplayer; }

private:
	sf::RenderWindow& mRenderWindow;
	DebuggerDisplayer mDebuggerDisplayer;
	sf::Clock mOneSecondClock;
	unsigned int mFramesPerSecond;
};

}
