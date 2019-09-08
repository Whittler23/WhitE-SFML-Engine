#include "States/StatesManager.hpp"
#include "States/baseState.hpp"
#include "window.hpp"

#include "Logger/logs.hpp"

namespace WhitE {

StatesManager::StatesManager(Window& renderWindow, ResourcesHolder& resourcesHolder)
	:mWindow(renderWindow)
	,mResources(resourcesHolder)
{
}

StatesManager::~StatesManager()
{
}

void StatesManager::draw()
{
	if (!mStack.empty() && !mStack.top()->getTransparent())
		mStack.top()->draw();
}

void StatesManager::input()
{
	if (!mStack.empty())
		mStack.top()->input();
}

void StatesManager::update(const sf::Time& deltaTime)
{
	if (!mStack.empty())
	{
		if (mStack.top()->shouldPop())
		{
			popState();
			return;
		}
		mStack.top()->update(deltaTime);
	}
}

void StatesManager::pushState(std::unique_ptr<BaseState> state)
{
	mStack.push(std::move(state));
	mStack.top()->onPush();

	WE_CORE_INFO("State pushed on stack");
}

void StatesManager::popState()
{
	if (!mStack.empty())
	{
		mStack.top()->onPop();
		mStack.pop();

		WE_CORE_INFO("State popped from stack");
	}
	else
		WE_CORE_ERROR("Attempt of operating on an empty stack!");
}

bool StatesManager::isEmpty()
{
	return mStack.empty();
}

}