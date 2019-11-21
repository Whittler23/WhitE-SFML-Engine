#pragma once

#include "Gui/widgetProperties.hpp"

#include <SFML/Graphics.hpp>

#include <string>

namespace WhitE::gui {

class GuiContainer;

class Widget
{
public:
	Widget();
	Widget(const std::string& widgetName);

	virtual void draw(sf::RenderTarget& renderTarget, const sf::RenderStates& renderStates) const;

	void setParent(GuiContainer* parentContainer);
	GuiContainer* getParent() const;

	void setPercentageSize(const sf::Vector2f& newPercentageSize);
	void setSize(const sf::Vector2f& newSize);
	sf::Vector2f getSize() const;
	sf::Vector2f getPercentSize() const;

	void setPercentagePosition(const sf::Vector2f& newPercentagePosition);
	void setPosition(const sf::Vector2f& newPosition);
	sf::Vector2f getPosition() const;
	sf::Vector2f getPercentPosition() const;

	std::string getName() const;

	void setVisible(bool isVisible);
	bool getVisible() const;

	void setEnabled(bool isEnabled);
	bool getEnabled() const;

	void setOpacity(int mOpacity);
	int getOpacity() const;

	void recalculateValues(const sf::Vector2f& prevViewSize);

protected:
	WidgetProperties mWidgetProperties;

private:
	GuiContainer* mParent; 

	sf::Sprite mSprite;
	std::string mWidgetName;
	int mOpacity;
	bool mVisible;
	bool mEnabled;
	bool mMouseHover;
};

}