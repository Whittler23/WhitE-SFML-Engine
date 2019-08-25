#include "Objects/gameEngineObject.hpp"
#include "Renderer/renderer.hpp"

namespace WhitE {

GameEngineObject::GameEngineObject(Renderer& renderer, const std::string& name)
	:mName(name)
	,mVisibility(false)
{
	//renderer.addToGameEngineObjects(this);
}

}