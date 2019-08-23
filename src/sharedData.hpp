#pragma once

#include "window.hpp"
#include "Resources/resourcesHolder.hpp"
#include "States/StatesManager.hpp"

namespace WhitE {

class Window;
class ResourcesHolder;
class StatesManager;

struct SharedData
{
	SharedData(Window& window, ResourcesHolder& resourcesHolder)
		:mWindow(window)
		,mResourcesHolder(resourcesHolder)
	{}

	Window& mWindow;
	ResourcesHolder& mResourcesHolder;
};

}