#pragma once

#include <SFML/Graphics.hpp>

namespace WhitE {

class DebuggerDisplayer : public sf::Drawable
{
public:
	DebuggerDisplayer(sf::RenderWindow& renderWindow);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void setFramesPerSecond(unsigned int fps);
	auto getText() -> sf::Text & { return mFPSText; }

private:
	void initializeText();

private:
	sf::Text mFPSText;
	sf::Font mFont;
};

}