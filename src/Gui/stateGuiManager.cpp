#include "Gui/stateGuiManager.hpp"
#include "Renderer/camera.hpp"
#include "Logger/logs.hpp"

namespace WhitE {

StateGuiManager::StateGuiManager(Camera& camera, sf::RenderTarget& renderTarget)
	:mRenderTarget(renderTarget)
	,mCamera(camera)
{
}

void StateGuiManager::updateGuiSets(const sf::Time& deltaTime)
{
	for (auto& guiSet : mGuiSets)
		guiSet->updateGuiElements(deltaTime);
}

void StateGuiManager::inputGuiSets()
{
	for (auto& guiSet : mGuiSets)
		guiSet->inputGuiElements();
}

void StateGuiManager::drawGuiSets() const
{
	sf::View tempView = mCamera.getView();
	mCamera.setView(mCamera.getDefaultView());

	for (auto& guiSet : mGuiSets)
		for (auto& guiElement : *guiSet->getGuiSetElements())
			mRenderTarget.draw(*guiElement);	

	mCamera.setView(tempView);
}

void StateGuiManager::addGuiSet(std::unique_ptr<BaseGuiSet> guiSet)
{
	WE_CORE_INFO("\"" + guiSet->getName() + "\" GUI set was added to the State Gui Manager");
	
	mGuiSets.emplace_back(std::move(guiSet));
}

void StateGuiManager::removeGuiSet(BaseGuiSet* baseGuiSet)
{
	for (auto it = mGuiSets.begin(); it != mGuiSets.end(); ++it)
		if (it->get() == baseGuiSet)
		{
			WE_CORE_INFO("\"" + baseGuiSet->getName() + "\" GUI set was erased from the State Gui Manager");
			mGuiSets.erase(it);
			return;
		}
}

void StateGuiManager::removeGuiSet(const std::string& guiSetName)
{
	for (auto it = mGuiSets.begin(); it != mGuiSets.end(); ++it)
		if ((*it)->getName() == guiSetName)
		{
			WE_CORE_INFO("\"" + guiSetName + "\" GUI set was erased from the State Gui Manager");
			mGuiSets.erase(it);
			return;
		}

	WE_CORE_WARNING("\"" + guiSetName + "\" GUI set does not exist and couldn't be erased from the State Gui Manager");
}

auto StateGuiManager::getGuiSets() -> std::list<std::unique_ptr<BaseGuiSet>>*
{
	return &mGuiSets;
}

}