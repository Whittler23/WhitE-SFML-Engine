#include "States/BaseState.hpp"
#include "Objects/entity.hpp"
#include "sharedData.hpp"

namespace WhitE {

BaseState::BaseState(SharedData& sharedData)
	:mSharedData(sharedData)
	,mRenderTarget(sharedData.mWindow.getRenderWindow())
	,mStateGuiManager(sharedData.mCamera, sharedData.mWindow.getRenderWindow())
	,mNextState(nullptr)
	,mTransparent(false)
	,mTrandescend(false)
	,mShouldPop(false)
{
}

BaseState::~BaseState()
{

}

}