#include "States/BaseState.hpp"
#include "Objects/gameObject.hpp"

namespace WhitE {

BaseState::BaseState()
	:mRootObject(std::make_unique<GameObject>("root"))
	,mTransparent(false)
	,mTrandescend(false)
	,mShouldPop(false)
{
}

BaseState::~BaseState()
{

}

}