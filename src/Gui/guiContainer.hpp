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

	void remove(const std::string& widgetName);
	void remove(const Widget& widget);
	void removeAllWidgets();

	void setContainerSize(const sf::Vector2f& newSize);
	sf::Vector2f getContainerSize() const;

	Widget* get(const std::string& widgetName) const;
	std::vector<Widget*> getWidgets() const;

private:
	void recalculateWidgetsValues();

private:
	std::unordered_map<std::string, std::unique_ptr<Widget>> mWidgetsMap;

	sf::Vector2f mContainerSize;
	sf::Vector2f mPreviousContainerSize;
};

}