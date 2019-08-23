#include "Debugger/dataCollector.hpp"
#include "Input/actionManager.hpp"

namespace WhitE {

DataCollector::DataCollector(Renderer& renderer)
	:mDebuggerDisplayer(renderer)
	,mFramesPerSecond(0)
{
}

void DataCollector::update(const sf::Time deltaTime)
{
	if (mOneSecondClock.getElapsedTime().asSeconds() >= 1.f)
	{
		mDebuggerDisplayer.setFramesPerSecond(mFramesPerSecond);
		mFramesPerSecond = 0;
		mOneSecondClock.restart();
	}
	else
		++mFramesPerSecond;
}

void DataCollector::input()
{
	bool shouldBeActive = getDebuggerDisplayer().shouldBeDrawn();
	if (ActionManager::isActionPressed("SwitchDebugger"))
		shouldBeActive = !shouldBeActive;
	getDebuggerDisplayer().setShouldBeDrawn(shouldBeActive);
}

}