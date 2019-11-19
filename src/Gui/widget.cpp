#include "Gui/widget.hpp"
#include "Gui/guiContainer.hpp"

namespace WhitE::gui {

Widget::Widget()
	:mParent(nullptr)
	,mWidgetName("widget")
	,mWidgetProperties(0.f, 0.f, 0.f, 0.f, sf::Vector2f(0.f, 0.f))
	,mOpacity(100)
	,mVisible(true)
	,mEnabled(true)
{
}

Widget::Widget(const std::string& widgetName)
	:mParent(nullptr)
	,mWidgetName(widgetName)
	,mWidgetProperties(0.f, 0.f, 0.f, 0.f, sf::Vector2f(0.f, 0.f))
	,mOpacity(100)
	,mVisible(true)
	,mEnabled(true)
{
}

void Widget::draw(sf::RenderTarget& renderTarget, const sf::RenderStates& renderStates) const
{
}

void Widget::setParent(GuiContainer* parentContainer)
{
	mParent = parentContainer;
}

GuiContainer* Widget::getParent() const
{
	return mParent;
}

void Widget::setSize(const sf::Vector2f& newPercentageSize)
{
	mWidgetProperties.setSize(newPercentageSize, mParent->getSize());
}

sf::Vector2f Widget::getSize() const
{
	return mWidgetProperties.getSize();
}

void Widget::setPosition(const sf::Vector2f& newPercentagePosition)
{
	mWidgetProperties.setPosition(newPercentagePosition, mParent->getPosition());
}

sf::Vector2f Widget::getPosition() const
{
	return mWidgetProperties.getPosition();
}

std::string Widget::getName() const
{
	return mWidgetName;
}

void Widget::setVisible(bool isVisible)
{
	mVisible = isVisible;
}

bool Widget::getVisible() const
{
	return mVisible;
}

void Widget::setEnabled(bool isEnabled)
{
	mEnabled = isEnabled;
}

bool Widget::getEnabled() const
{
	return mEnabled;
}

void Widget::setOpacity(int opacity)
{
	mOpacity = opacity;
}

int Widget::getOpacity() const
{
	return mOpacity;
}

/////////////////////////////////////////////////////////////
						//PRIVATE
/////////////////////////////////////////////////////////////
	
void Widget::recalculateValues(const sf::Vector2f& prevViewSize)
{
	mWidgetProperties.recalculateValues(prevViewSize, mParent->getSize());
}

/////////////////////////////////////////////////////////////

}