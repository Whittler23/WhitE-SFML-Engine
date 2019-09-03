#include "States/BaseState.hpp"
#include "Objects/entity.hpp"
#include "sharedData.hpp"
#include "Renderer/stateRenderer.hpp"

namespace WhitE {

BaseState::BaseState(SharedData& sharedData)
	:mSharedData(sharedData)
	,mStateGuiManager(sharedData.mCamera, sharedData.mWindow.getRenderWindow())
	,mRootObject(std::make_unique<Entity>("root"))
	,mStateRenderer(getSharedData().mWindow.getRenderWindow())
	,mTransparent(false)
	,mTrandescend(false)
	,mShouldPop(false)
{
}

BaseState::~BaseState()
{

}

}