#include "Objects/gameObject.hpp"
#include "Logger/logs.hpp"

namespace WhitE {

GameObject::GameObject(const std::string& name)
	:mParent(nullptr)
	,mName(name)
{
}

void GameObject::addChild(std::unique_ptr<GameObject> gameObject)
{
	gameObject->setParent(this);
	WE_CORE_INFO("\"" + gameObject->getName() + "\" was added as the child of \"" + getName() + "\"");
	mChildren.emplace_back(std::move(gameObject));
}

void GameObject::removeChild(const std::string& nameOfObjectToRemove)
{
	for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
	{
		if ((*it)->getName() == nameOfObjectToRemove)
		{
			WE_CORE_INFO("\"" + (*it)->getName() + "\" which was child of \"" + getName() + "\" was removed");
			mChildren.erase(it);
			return;
		}
	}
	WE_CORE_INFO("\"" + nameOfObjectToRemove + "\" is not a child of \"" + getName() + "\" and could not be removed");
}

void GameObject::removeChild(GameObject* gameObjectToRemove)
{
	for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
	{
		if (it->get() == gameObjectToRemove)
		{
			mChildren.erase(it);
			WE_CORE_INFO("\"" + (*it)->getName() + "\" which was child of \"" + getName() + "\" was removed");
			return;
		}
	}
	WE_CORE_INFO("\"" + gameObjectToRemove->getName() + "\" is not a child of \"" + getName() + "\" and could not be removed");
}

}