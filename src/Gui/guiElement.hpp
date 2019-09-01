#pragma once

#include <SFML/Graphics.hpp>

namespace WhitE {

struct SharedData;

class GuiElement : public sf::Drawable
{
public:
	GuiElement(SharedData& sharedData, const std::string& name);

	virtual void update(const sf::Time& deltaTime);
	virtual void input();

	auto getName() const -> const std::string &;

protected:
	SharedData& mSharedData;
	std::string mGuiElementName;
	bool mVisible;
};

}