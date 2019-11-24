#include "Gui/guiContainer.hpp"
#include "Gui/widgetProperties.hpp"

#include "Logger/logs.hpp"

namespace WhitE::gui {

/////////////////////////////////////////////////////////////
					//CONSTRUCTORS
/////////////////////////////////////////////////////////////

GuiContainer::GuiContainer()
	:Widget("GuiContainer")
{
}

/////////////////////////////////////////////////////////////
						//PUBLIC
/////////////////////////////////////////////////////////////

void GuiContainer::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	for (const auto& widget : mWidgetsMap)
		if(widget.second->getVisible())
			widget.second->draw(renderTarget, renderStates);
}

void GuiContainer::addWidget(const std::string& widgetName, std::unique_ptr<Widget> newWidget)
{
	newWidget->setParent(this);
	mWidgetsMap.emplace(std::make_pair(widgetName, std::move(newWidget)));
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

void GuiContainer::setContainerSize(const sf::Vector2f& newSize)
{
	mPreviousContainerSize = mContainerSize;
	mContainerSize = newSize;
	recalculateWidgetsValues();
}

sf::Vector2f GuiContainer::getContainerSize() const
{
	return mContainerSize;
}

Widget* GuiContainer::get(const std::string& widgetName) const
{
	return mWidgetsMap.at(widgetName).get();
}

std::vector<Widget*> GuiContainer::getWidgets() const
{
	std::vector<Widget*> widgets;
	for (const auto& widget : mWidgetsMap)
		widgets.emplace_back(widget.second.get());
	return widgets;
}

/////////////////////////////////////////////////////////////
						//PRIVATE
/////////////////////////////////////////////////////////////

void GuiContainer::recalculateWidgetsValues()
{
	for (auto& widget : mWidgetsMap)
		widget.second->recalculateValues(mPreviousContainerSize);
}

/////////////////////////////////////////////////////////////

}
