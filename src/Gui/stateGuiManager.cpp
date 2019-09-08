#include "Gui/stateGuiManager.hpp"
#include "Renderer/camera.hpp"
#include "Logger/logs.hpp"

namespace WhitE {

StateGuiManager::StateGuiManager(Camera& camera, sf::RenderTarget& renderTarget)
	:mRenderTarget(renderTarget)
	,mCamera(camera)
{
}

void StateGuiManager::updateGuiElements(const sf::Time& deltaTime)
{
	for (auto& guiElement : mGuiElements)
		guiElement->update(deltaTime);
}

void StateGuiManager::inputGuiElements()
{
	for (auto& guiElement : mGuiElements)
		guiElement->input();
	for (auto& guiButton : mGuiButtons)
		guiButton->input();
}

void StateGuiManager::drawGuiElements() const
{
	sf::View tempView = mCamera.getView();
	mCamera.setView(mCamera.getDefaultView());

	for (auto& guiElement : mGuiElements)
		mRenderTarget.draw(*guiElement);
	for (auto& guiButton : mGuiButtons)
		mRenderTarget.draw(*guiButton);

	mCamera.setView(tempView);
}

void StateGuiManager::addGuiElement(std::unique_ptr<GuiElement> guiSet)
{
	WE_CORE_INFO("\"" + guiSet->getName() + "\" GUI set was added to the State Gui Manager");
	
	mGuiElements.emplace_back(std::move(guiSet));
}

void StateGuiManager::addGuiButton(std::unique_ptr<Button> guiButton)
{
	WE_CORE_INFO("\"" + guiButton->getName() + "\" GUI set was added to the State Gui Manager");

	mGuiButtons.emplace_back(std::move(guiButton));
}

void StateGuiManager::removeGuiElement(const std::string& guiSetName)
{
	for (auto it = mGuiElements.begin(); it != mGuiElements.end(); ++it)
		if ((*it)->getName() == guiSetName)
		{
			WE_CORE_INFO("\"" + guiSetName + "\" GUI set was erased from the State Gui Manager");
			mGuiElements.erase(it);
			return;
		}

	WE_CORE_WARNING("\"" + guiSetName + "\" GUI set does not exist and couldn't be erased from the State Gui Manager");
}

}