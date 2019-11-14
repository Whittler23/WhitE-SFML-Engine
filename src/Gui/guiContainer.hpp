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

	void draw(const sf::RenderTarget& renderTarget, sf::RenderStates renderStates = sf::RenderStates::Default) const;

	void addWidget(const std::string& widgetName, std::unique_ptr<Widget> newWidget);

	Widget* get(const std::string& widgetName);
	Widget* get(const Widget& widget);
	std::vector<std::unique_ptr<Widget>>& getWidgets();

	void remove(const std::string& widgetName);
	void remove(const Widget& widget);
	void removeAllWidgets();

	void setSize(sf::Vector2f newSize);
	sf::Vector2f getSize();

private:
	std::unordered_map<std::string, std::unique_ptr<Widget>> mWidgetsMap;

	//NOTE: Below variables are relative to the window size
	sf::Vector2f mContainerSize;
	sf::Vector2f mContainerPosition;
};

}