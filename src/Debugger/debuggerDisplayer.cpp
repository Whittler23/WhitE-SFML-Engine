#include "Debugger/debuggerDisplayer.hpp"
#include "Resources/resourcesHolder.hpp"

namespace WhitE {

DebuggerDisplayer::DebuggerDisplayer(Renderer& renderer)
	:GameEngineObject(renderer, "DebuggerDisplayer")
	,mShouldBeDrawn(false)
{
}

void DebuggerDisplayer::initializeText(ResourcesHolder& resourcesHolder)
{
	mFPSText.setFont(resourcesHolder.getFontHolder().get("testFont"));
	mFPSText.setPosition(sf::Vector2f(500.f, 30.f));
}

void DebuggerDisplayer::setFramesPerSecond(unsigned int fps)
{
	mFPSText.setString("FPS: " + std::to_string(fps));
}

void DebuggerDisplayer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(mShouldBeDrawn)
		target.draw(mFPSText);
}

}