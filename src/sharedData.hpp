#pragma once

#include "Window/window.hpp"
#include "Resources/resourcesHolder.hpp"
#include "States/StatesManager.hpp"

namespace WhitE {

class Window;
class ResourcesHolder;
class StatesManager;

struct SharedData
{
	SharedData(Window& window, ResourcesHolder& resourcesHolder, StatesManager& statesManager)
		:mWindow(window)
		,mResourcesHolder(resourcesHolder)
		,mStatesManager(statesManager)
	{}

	Window& mWindow;
	ResourcesHolder& mResourcesHolder;
	StatesManager& mStatesManager;
};

}