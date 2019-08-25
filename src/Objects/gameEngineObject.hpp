#pragma once

#include "Objects/drawableGameObject.hpp"

namespace WhitE {

class GameEngineObject : public sf::Drawable
{
public:
	GameEngineObject(Renderer& renderer, const std::string& name);

	bool isVisible() { return mVisibility; }
	void setVisibility(const bool visibility) { mVisibility = visibility; }

private:
	std::string mName;
	bool mVisibility;
};

}