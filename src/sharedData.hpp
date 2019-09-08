#pragma once

#include "window.hpp"
#include "Resources/resourcesHolder.hpp"
#include "Renderer/camera.hpp"

namespace WhitE {

class Window;
class ResourcesHolder;
class Camera;

struct SharedData
{
	SharedData(Window& window, ResourcesHolder& resourcesHolder, Camera& camera)
		:mWindow(window)
		,mResourcesHolder(resourcesHolder)
		,mCamera(camera)
	{}

	Window& mWindow;
	ResourcesHolder& mResourcesHolder;
	Camera& mCamera;

	ResourcesManager<sf::Texture>& getTextures() { return mResourcesHolder.getTextureHolder(); }
	ResourcesManager<sf::Font>& getFonts() { return mResourcesHolder.getFontHolder(); }
	ResourcesManager<sf::SoundBuffer>& getSounds() { return mResourcesHolder.getSoundHolder(); }
};

}