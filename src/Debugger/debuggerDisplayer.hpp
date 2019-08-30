#pragma once

#include "Objects/gameEngineObject.hpp"

#include <SFML/Graphics.hpp>

namespace WhitE {

class Renderer;
class ResourcesHolder;

class DebuggerDisplayer : public GameEngineObject
{
public:
	DebuggerDisplayer(Renderer& renderer);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void setFramesPerSecond(unsigned int fps);
	auto getText() -> sf::Text & { return mFPSText; }

	void setShouldBeDrawn(const bool shouldBeDrawn) { mShouldBeDrawn = shouldBeDrawn; }
	bool shouldBeDrawn() { return mShouldBeDrawn; }

private:
	void initializeText(ResourcesHolder& resourcesHolder);

private:
	sf::Text mFPSText;
	bool mShouldBeDrawn;

	friend class DataCollector;
};

}