#pragma once

#include "Gui/widget.hpp"

#include <SFML/Graphics.hpp>

#include <unordered_map>
#include <memory>

namespace WhitE::gui {

class Widget;

class GuiContainer : public Widget
{
public:
	GuiContainer();

	void draw(sf::RenderTarget& renderTarget, const sf::RenderStates renderStates = sf::RenderStates::Default) const;

	void addWidget(const std::string& widgetName, std::unique_ptr<Widget> newWidget);

	Widget* get(const std::string& widgetName);
	std::vector<Widget*> getWidgets();

	void remove(const std::string& widgetName);
	void remove(const Widget& widget);
	void removeAllWidgets();

	void setSize(const sf::Vector2f& newSize);
	sf::Vector2f getSize();

	void setPosition(const sf::Vector2f& newPosition);
	sf::Vector2f getPosition();

private:
	std::unordered_map<std::string, std::unique_ptr<Widget>> mWidgetsMap;

	//NOTE: Below variables are relative to the window size
	sf::Vector2f mContainerSize;
	sf::Vector2f mContainerPosition;
};

}