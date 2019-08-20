#include "Objects/gameObject.hpp"
#include "Logger/logs.hpp"

namespace WhitE {

GameObject::GameObject(const std::string& name)
	:mParent(nullptr)
{
}

void GameObject::addChild(GameObject* gameObject)
{
	gameObject->setParent(this);
	mChildren.emplace_back(gameObject);
	WE_CORE_INFO("\"" + gameObject->getName() + "\" was added as the child of \"" + getName() + "\"");
}

void GameObject::removeChild(const std::string& nameOfObjectToRemove)
{
	for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
	{
		if ((*it)->getName() == nameOfObjectToRemove)
		{
			mChildren.erase(it);
			WE_CORE_INFO("\"" + (*it)->getName() + "\" which was child of \"" + getName() + "\" was removed");
		}
	}
}

void GameObject::removeChild(GameObject* gameObjectToRemove)
{
	for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
	{
		if (it->get() == gameObjectToRemove)
		{
			mChildren.erase(it);
			WE_CORE_INFO("\"" + (*it)->getName() + "\" which was child of \"" + getName() + "\" was removed");
		}
	}
}

}