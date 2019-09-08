#pragma once

#include "sharedData.hpp"
#include "Gui/guiElement.hpp"

namespace WhitE {

class Button : public GuiElement
{
public:
	Button(SharedData& sharedData, const sf::Vector2f& percentPosition, const sf::Vector2f& percentSize, const std::string& text);
	~Button();

	enum class ButtonState {Idle, Hover, Press};

	void init(const sf::Vector2f& percentPosition, const sf::Vector2f& percentSize);

	void update(const sf::Time& deltaTime) override;
	void input() override;
	void draw(sf::RenderTarget& rt, sf::RenderStates) const override;

	bool isPressed();

private:
	void onIdle();
	void onHover();
	void onPress();

private:
	sf::Color mIdleColor;
	sf::Color mHoverColor;
	sf::Color mPressColor;

	sf::RectangleShape mButtonBackground;
	sf::Text mButtonText;
	sf::Vector2f mPosition;
	Button::ButtonState mButtonState;
};

}