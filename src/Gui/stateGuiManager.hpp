#pragma once

#include "Gui/baseGuiSet.hpp"

namespace WhitE {

class Camera;

class StateGuiManager
{
public:
	StateGuiManager(Camera& camera, sf::RenderTarget& renderTarget);


	void updateGuiSets(const sf::Time& deltaTime);
	void inputGuiSets();
	void drawGuiSets() const;

	void addGuiSet(std::unique_ptr<BaseGuiSet> baseGuiSet);
	void removeGuiSet(BaseGuiSet* baseGuiSet);
	void removeGuiSet(const std::string& guiSetName);

	auto getGuiSets()->std::list<std::unique_ptr<BaseGuiSet>>*;

private:
	sf::RenderTarget& mRenderTarget;
	Camera& mCamera;
	std::list<std::unique_ptr<BaseGuiSet>> mGuiSets;

};

}