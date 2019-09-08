#pragma once

#include "Gui/guiElement.hpp"
#include "GuiElements/button.hpp"

#include <list>

namespace WhitE {

class Camera;

class StateGuiManager
{
public:
	StateGuiManager(Camera& camera, sf::RenderTarget& renderTarget);

	void updateGuiElements(const sf::Time& deltaTime);
	void inputGuiElements();
	void drawGuiElements() const;

	void addGuiElement(std::unique_ptr<GuiElement> guiElement);
	void addGuiButton(std::pair<std::string, std::unique_ptr<Button>> guiButton);
	void removeGuiElement(const std::string& guiElementName);

	auto getGuiButtons()->std::unordered_map<std::string, std::unique_ptr<Button>>& { return mGuiButtons; }

private:
	sf::RenderTarget& mRenderTarget;
	Camera& mCamera;
	std::list<std::unique_ptr<GuiElement>> mGuiElements;
	std::unordered_map<std::string, std::unique_ptr<Button>> mGuiButtons;

};

}