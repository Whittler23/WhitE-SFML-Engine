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
	if (mStack.empty() || mStack.top()->getTransparent())
		return;
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
	if (!mStack.empty())
		mStack.top()->onCover();
	//Most likely temporary solution

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
		if (!mStack.empty())
			mStack.top()->onPush();

		WE_CORE_INFO("State popped from stack");
	}
	else
		WE_CORE_ERROR("Attempt of operating on an empty stack!");
}

void StatesManager::replaceState(std::unique_ptr<BaseState> state)
{
	if (!mStack.empty())
	{
		mStack.pop();
		mStack.push(std::move(state));
		WE_CORE_INFO("Replaced popped from stack");
	}
	else
		WE_CORE_ERROR("Attempt of operating on an empty stack!");
}

}