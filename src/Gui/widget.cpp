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
		sf::RectangleShape rect({ 400.f, 400.f });
		rect.setFillColor(sf::Color::Red);

		renderTarget.draw(rect, renderStates);
	}

	void Widget::setParent(GuiContainer* parentContainer)
	{
		mParent = parentContainer;
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

}