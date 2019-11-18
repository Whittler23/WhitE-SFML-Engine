#pragma once

#include "Gui/guiContainer.hpp"

#include <SFML/Graphics.hpp>

#include <unordered_map>
#include <string>
#include <memory>

namespace WhitE::gui {

class Widget;

class GuiManager
{
public:
	GuiManager(sf::RenderTarget& renderTarget);
	GuiManager(sf::RenderTarget& renderTarget, const sf::View& view);

	void draw() const;

	void setView(const sf::View& newView);

	void addWidget(const std::string& widgetName, std::unique_ptr<Widget> newWidget);

	Widget* get(const std::string& widgetName);
	std::vector<Widget*> getWidgets();

	void remove(const std::string& widgetName);
	void remove(const Widget& widget);
	void removeAllWidgets();

	std::vector<std::string> getWidgetNames();

	sf::View getView();

private:
	sf::View mGuiView;
	GuiContainer mGuiContainer;

	sf::RenderTarget& mRenderTarget;
};

}