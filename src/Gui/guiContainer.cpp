#include "Gui/guiContainer.hpp"

#include "Logger/logs.hpp"

namespace WhitE::gui {

GuiContainer::GuiContainer()
{

}

void GuiContainer::draw(const sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	for (const auto& widget : mWidgetsMap)
		widget.second->draw(renderTarget, renderStates);
}

void GuiContainer::addWidget(const std::string& widgetName, std::unique_ptr<Widget> newWidget)
{
	newWidget->setParent(this);
	mWidgetsMap.emplace(std::make_pair(widgetName, std::move(newWidget)));
}

Widget* GuiContainer::get(const std::string& widgetName)
{
	return mWidgetsMap.at(widgetName).get();
}

std::vector<Widget*> GuiContainer::getWidgets()
{
	std::vector<Widget*> widgets;
	for (const auto& widget : mWidgetsMap)
		widgets.emplace_back(widget.second.get());
	return widgets;
}

void GuiContainer::remove(const std::string& widgetName)
{
	mWidgetsMap.erase(widgetName);
}

void GuiContainer::remove(const Widget& widget)
{
	for (auto it = mWidgetsMap.begin(); it != mWidgetsMap.end(); ++it)
		if (it->second.get() == &widget)
			mWidgetsMap.erase(it);
}

void GuiContainer::removeAllWidgets()
{
	mWidgetsMap.clear();
}

void GuiContainer::setSize(const sf::Vector2f& newSize)
{
	mContainerSize = newSize;
}

sf::Vector2f GuiContainer::getSize()
{
	return mContainerSize;
}

void GuiContainer::setPosition(const sf::Vector2f& newPosition)
{
	mContainerPosition = newPosition;
}

sf::Vector2f GuiContainer::getPosition()
{
	return mContainerPosition;
}

}