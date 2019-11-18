#include "guiManager.hpp"

namespace WhitE::gui{

GuiManager::GuiManager(sf::RenderTarget& renderTarget)
	:mRenderTarget(renderTarget)
	,mGuiView(renderTarget.getView())
{
	mGuiContainer.setSize(mGuiView.getSize());
}

GuiManager::GuiManager(sf::RenderTarget& renderTarget, const sf::View& view)
	:mRenderTarget(renderTarget)
	,mGuiView(view)
{
	mGuiContainer.setSize(mGuiView.getSize());
}

void GuiManager::draw() const
{
	const sf::View gameWorldView = mRenderTarget.getView();
	mRenderTarget.setView(mGuiView);

	mGuiContainer.draw(mRenderTarget);

	mRenderTarget.setView(gameWorldView);
}

void GuiManager::addWidget(const std::string& widgetName, std::unique_ptr<Widget> newWidget)
{
	mGuiContainer.addWidget(widgetName, std::move(newWidget));
}

Widget* GuiManager::get(const std::string& widgetName)
{
	return mGuiContainer.get(widgetName);
}

std::vector<Widget*> GuiManager::getWidgets()
{
	return mGuiContainer.getWidgets();
}

void GuiManager::remove(const std::string& widgetName)
{
	mGuiContainer.remove(widgetName);
}

void GuiManager::remove(const Widget& widget)
{
	mGuiContainer.remove(widget);
}

void GuiManager::removeAllWidgets()
{
	mGuiContainer.removeAllWidgets();
}

std::vector<std::string> GuiManager::getWidgetNames()
{
	return std::vector<std::string>();
}

sf::View GuiManager::getView()
{
	return mGuiView;
}

void GuiManager::setView(const sf::View& newView)
{
	mGuiView = newView;
	mGuiContainer.setSize(newView.getSize());
	mGuiContainer.setPosition(newView.getCenter());

	//TODO: Change in the view must be followed by the changes
	//		in the gui widgets' sizes
}

}
