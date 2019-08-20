#include "Objects/drawableGameObject.hpp"

namespace WhitE {

DrawableGameObject::DrawableGameObject(const std::string& name)
	:GameObject(name)
	,mVisibility(true)
	,mRotation(0.f)
	,mScale(0.f, 0.f)
	,mPosition(0.f, 0.f)
{

}

}