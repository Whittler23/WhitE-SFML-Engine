#pragma once

#include "window.hpp"
#include "Resources/resourcesHolder.hpp"
#include "States/StatesManager.hpp"

namespace WhitE {

class Window;
class ResourcesHolder;
class StatesManager;
class Renderer;

struct SharedData
{
	SharedData(Window& window, ResourcesHolder& resourcesHolder, Renderer& renderer)
		:mWindow(window)
		,mResourcesHolder(resourcesHolder)
		,mRenderer(renderer)
	{}

	Window& mWindow;
	ResourcesHolder& mResourcesHolder;
	Renderer& mRenderer;
};

}