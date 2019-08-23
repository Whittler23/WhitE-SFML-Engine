#include "Debugger/debuggerDisplayer.hpp"

namespace WhitE {

DebuggerDisplayer::DebuggerDisplayer(Renderer& renderer)
	:DrawableGameObject(renderer, LayerType::EngineObjects, "DebuggerDisplayer")
	,mShouldBeDrawn(false)
{
	initializeText();
}

void DebuggerDisplayer::initializeText()
{
	mFont.loadFromFile("G:/WhitE/resources/fonts/testFont.ttf");
	mFPSText.setFont(mFont);
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