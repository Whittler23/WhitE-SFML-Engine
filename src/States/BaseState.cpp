#include "States/BaseState.hpp"
#include "Objects/gameObject.hpp"
#include "sharedData.hpp"
#include "Renderer/stateRenderer.hpp"

namespace WhitE {

BaseState::BaseState(SharedData& sharedData)
	:mSharedData(sharedData)
	,mRootObject(std::make_unique<GameObject>("root"))
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