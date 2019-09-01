#pragma once

#include "sharedData.hpp"
#include "Gui/guiElement.hpp"

namespace WhitE {

class Button : public GuiElement
{
public:
	Button(SharedData& sharedData, const sf::Vector2f& percentPosition, const sf::Vector2f& percentSize, const std::string& text);
	~Button();

	void init(const sf::Vector2f& percentPosition, const sf::Vector2f& percentSize);

	void update(const sf::Time& deltaTime) override;
	void input() override;
	void draw(sf::RenderTarget& rt, sf::RenderStates) const override;

private:
	sf::Color mIdleColor;
	sf::Color mHoverColor;
	sf::RectangleShape mButtonBackground;
	sf::Text mButtonText;
	sf::Vector2f mPosition;
};

}