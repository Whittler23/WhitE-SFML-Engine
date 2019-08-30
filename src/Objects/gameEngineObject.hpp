#pragma once

#include "Renderer/renderer.hpp"

namespace WhitE {

class GameEngineObject : public sf::Drawable
{
public:
	GameEngineObject(Renderer& renderer, const std::string& name);

	bool isVisible() { return mVisibility; }
	void setVisibility(const bool visibility) { mVisibility = visibility; }

	auto getName() const -> const std::string & { return mName; }

private:
	std::string mName;
	bool mVisibility;
};

}