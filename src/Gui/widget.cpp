#include "Gui/widget.hpp"
#include "Gui/guiContainer.hpp"
#include <iostream>

namespace WhitE::gui {

Widget::Widget()
	:mParent(nullptr)
	,mWidgetName("widget")
	,mWidgetProperties(0.f, 0.f, 0.f, 0.f, sf::Vector2f(0.f, 0.f))
	,mOpacity(100)
	,mVisible(true)
	,mEnabled(true)
	,mMouseHover(false)
{
}

Widget::Widget(const std::string& widgetName)
	:mParent(nullptr)
	,mWidgetName(widgetName)
	,mWidgetProperties(0.f, 0.f, 0.f, 0.f, sf::Vector2f(0.f, 0.f))
	,mOpacity(100)
	,mVisible(true)
	,mEnabled(true)
	,mMouseHover(false)
{
}

void Widget::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	renderStates.transform.translate(getPosition());
	renderTarget.draw(mSprite, renderStates);
}

void Widget::setParent(GuiContainer* parentContainer)
{
	mParent = parentContainer;
}

GuiContainer* Widget::getParent() const
{
	return mParent;
}

void Widget::setTexture(sf::Texture& widgetTexture)
{
	mSprite.setTexture(widgetTexture);
}

bool Widget::hasTexture() const
{
	return mSprite.getTexture();
}

const sf::Texture* Widget::getTexture() const
{
	return mSprite.getTexture();
}

void Widget::setPercentageSize(const sf::Vector2f& newPercentageSize)
{
	mWidgetProperties.setPercentageSize(newPercentageSize, getParent()->getContainerSize());
}

void Widget::setSize(const sf::Vector2f& newSize)
{
	mWidgetProperties.setSize(newSize);
}

sf::Vector2f Widget::getSize() const
{
	return mWidgetProperties.getSize();
}

sf::Vector2f Widget::getPercentSize() const
{
	return mWidgetProperties.getPercentageSize(getParent()->getContainerSize());
}

void Widget::setPercentagePosition(const sf::Vector2f& newPercentagePosition)
{
	mWidgetProperties.setPercentagePosition(newPercentagePosition, mParent->getContainerSize());
}

void Widget::setPosition(const sf::Vector2f& newPosition)
{
	mWidgetProperties.setPosition(newPosition);
}

sf::Vector2f Widget::getPosition() const
{
	return mWidgetProperties.getPosition();
}

sf::Vector2f Widget::getPercentPosition() const
{
	return mWidgetProperties.getPercentagePosition(getParent()->getContainerSize());
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