#pragma once

#include <list>

namespace WhitE {

class GuiElement;

class StatesGui 
{
public:
	StatesGui();

	void addGuiElement(GuiElement* guiElement);
	void removeGuiElement(GuiElement* guiElement);

	auto getStatesGui() const -> const std::list<GuiElement*>&;

private:
	std::list<GuiElement*> mStatesGui;

};

}
