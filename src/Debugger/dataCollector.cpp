#include "Debugger/dataCollector.hpp"

namespace WhitE {

DataCollector::DataCollector(sf::RenderWindow& renderWindow)
	:mRenderWindow(renderWindow)
	,mDebuggerDisplayer(renderWindow)
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

}