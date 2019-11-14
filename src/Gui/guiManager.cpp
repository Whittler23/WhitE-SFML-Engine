#include "guiManager.hpp"

namespace WhitE::gui{

GuiManager::GuiManager(sf::RenderTarget& renderTarget)
	:mRenderTarget(renderTarget)
	,mGuiView()
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

void GuiManager::setView(const sf::View& newView)
{
	mGuiView = newView;

	//TODO: Change in the view must be followed by the changes
	//		in the gui widgets' sizes
}

}
