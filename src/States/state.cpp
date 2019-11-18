#include "States/state.hpp"
#include "sharedData.hpp"

namespace WhitE {

State::State(SharedData& sharedData)
	:mSharedData(sharedData)
	,mRenderTarget(sharedData.mWindow.getRenderWindow())
	,mNextState(nullptr)
	,mTransparent(false)
	,mTrandescend(false)
	,mShouldPop(false)
{
}

State::~State()
{

}

}