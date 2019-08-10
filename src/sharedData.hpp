#pragma once

#include "Window/window.hpp"
#include "Resources/resourcesHolder.hpp"
#include "States/StatesManager.hpp"

namespace WhitE {

class Window;
class ResourceHolder;
class StatesManager;

struct SharedData
{
	SharedData(Window& window, ResourceHolder& resourceHolder, StatesManager& statesManager)
		:mWindow(window)
		,mResourceHolder(resourceHolder)
		,mStatesManager(statesManager)
	{}

	Window& mWindow;
	ResourceHolder& mResourceHolder;
	StatesManager& mStatesManager;
};

}