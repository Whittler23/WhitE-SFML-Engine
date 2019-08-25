#include "Objects/drawableGameObject.hpp"
#include "Renderer/renderer.hpp"

namespace WhitE {

DrawableGameObject::DrawableGameObject(Renderer& renderer, LayerType layerType, const std::string& name)
	:mRenderer(renderer)
	,GameObject(name)
	,mVisibility(true)
	,mRotation(0.f)
	,mScale(0.f, 0.f)
	,mPosition(0.f, 0.f)
{
	mRenderer.addObjectToDrawables(layerType, this);
}

}