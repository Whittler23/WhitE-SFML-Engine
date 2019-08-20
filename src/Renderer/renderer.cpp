#include "Renderer/renderer.hpp"
#include "Logger/logs.hpp"
#include "Window/window.hpp"

namespace WhitE {

Renderer::Renderer(sf::RenderTarget& renderTarget)
	:mRenderTarget(renderTarget)
{
	WE_CORE_INFO("Initialized state renderer");
}

Renderer::~Renderer()
{
	WE_CORE_INFO("Deleted state renderer");
}

void Renderer::draw() 
{
	//sf::Text elo;
	//for (const auto& objectToDraw : mDrawableSet)
	//{
	//	mRenderTarget.draw(objectToDraw);
	//}
}


}