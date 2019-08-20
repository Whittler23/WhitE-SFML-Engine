#include "States/StatesManager.hpp"
#include "States/baseState.hpp"
#include "Window/window.hpp"

#include "Logger/logs.hpp"

namespace WhitE {

StatesManager::StatesManager(Window& renderWindow, ResourceHolder& resourcesHolder)
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
		mStack.top()->update(deltaTime);
}

void StatesManager::pushScene(std::unique_ptr<BaseState> state)
{
	mStack.push(std::move(state));

	WE_CORE_INFO("State pushed on stack!");
}

void StatesManager::popScene()
{
	if (!mStack.empty())
	{
		mStack.pop();
	}

	WE_CORE_INFO("State popped from stack!");
}

}