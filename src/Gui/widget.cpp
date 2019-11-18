#include "Gui/widget.hpp"

namespace WhitE::gui {



	Widget::Widget()
		:mParent(nullptr)
		,mWidgetName("widget")
		,mSize({0, 0})
		,mPosition({0, 0})
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

	void Widget::setSize(const sf::Vector2f& newSize)
	{
		mSize = newSize;
	}

	void Widget::setPosition(const sf::Vector2f& newPosition)
	{
		mPosition = newPosition;
	}

	sf::Vector2f Widget::getSize()
	{
		return mSize;
	}

	sf::Vector2f Widget::getPosition()
	{
		return mPosition;
	}

	GuiContainer* Widget::getParent()
	{
		return mParent;
	}

	std::string Widget::getName()
	{
		return mWidgetName;
	}

	bool Widget::getVisible()
	{
		return mVisible;
	}

	bool Widget::getEnabled()
	{
		return mEnabled;
	}

}