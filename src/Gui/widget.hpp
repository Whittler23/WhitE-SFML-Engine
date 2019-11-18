#pragma once

#include <SFML/Graphics.hpp>

#include <string>

namespace WhitE::gui {

class GuiContainer;

class Widget
{
public:
	Widget();

	void draw(sf::RenderTarget& renderTarget, const sf::RenderStates& renderStates) const;

	void setParent(GuiContainer* parentContainer);

	void setSize(const sf::Vector2f& newSize);
	void setPosition(const sf::Vector2f& newPosition);

	sf::Vector2f getSize();
	sf::Vector2f getPosition();

	GuiContainer* getParent();
	std::string getName();

	bool getVisible();
	bool getEnabled();

private:
	std::string mWidgetName;
	GuiContainer* mParent;

	//NOTE: Below variables are relative to the container size
	sf::Vector2f mSize;
	sf::Vector2f mPosition;

	int mOpacity;
	bool mVisible;
	bool mEnabled;
};

}