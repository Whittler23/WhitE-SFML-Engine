#pragma once

#include "sharedData.hpp"
#include "Gui/guiElement.hpp"

namespace WhitE {

class Button : public GuiElement
{
public:
	Button(SharedData& sharedData, const sf::Vector2f& percentPosition, const sf::Vector2f& percentSize,
		sf::Color idleColor, sf::Color hoverColor, sf::Color pressColor,
		const std::string& text, const float buttonOutlines = 0.f, const unsigned fontSize = 30.f,
		const std::string& textureName = "", const std::string& fontName = "");
	~Button();


	void update(const sf::Time& deltaTime) override;
	void input() override;
	void draw(sf::RenderTarget& rt, sf::RenderStates) const override;

	bool isPressed();

private:
	void init(const sf::Vector2f& percentPosition, const sf::Vector2f& percentSize, const float buttonOutlines, const unsigned fontSize);
	void loadGraphics(const std::string& textureName, const std::string& fontName);

	sf::Vector2f getTextPosition();

	void onIdle();
	void onHover();
	void onPress();

	enum class ButtonState {Idle, Hover, Press};

private:
	sf::Color mIdleColor;
	sf::Color mHoverColor;
	sf::Color mPressColor;

	sf::RectangleShape mButtonBox;
	sf::Text mButtonText;
	sf::Vector2f mPosition;
	ButtonState mButtonState;
};

}