#pragma once

#include "Objects/drawableGameObject.hpp"

#include <SFML/Graphics.hpp>

namespace WhitE {

class DebuggerDisplayer : public DrawableGameObject
{
public:
	DebuggerDisplayer(sf::RenderWindow& renderWindow);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void setFramesPerSecond(unsigned int fps);
	auto getText() -> sf::Text & { return mFPSText; }

	void setShouldBeDrawn(const bool shouldBeDrawn) { mShouldBeDrawn = shouldBeDrawn; }
	bool shouldBeDrawn() { return mShouldBeDrawn; }

private:
	void initializeText();

private:
	sf::Text mFPSText;
	sf::Font mFont;
	bool mShouldBeDrawn;
};

}