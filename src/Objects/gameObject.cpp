#include "Objects/gameObject.hpp"
#include "Logger/logs.hpp"

namespace WhitE {

GameObject::GameObject(const std::string& name)
	:mParent(nullptr)
	,mName(name)
{
}

void GameObject::updateObjects(const sf::Time& deltaTime)
{
	update(deltaTime);
	updateChildren(deltaTime);
}

void GameObject::inputObjects()
{
	input();
	inputChildren();
}

void GameObject::update(const sf::Time& deltaTime)
{
}

void GameObject::updateChildren(const sf::Time& deltaTime)
{
	for (auto& child : mChildren)
	{
		child->updateObjects(deltaTime);
	}
}

void GameObject::input()
{
}

void GameObject::inputChildren()
{
	for (auto& child : mChildren)
	{
		child->inputObjects();
	}
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
		if ((*it)->getName() == nameOfObjectToRemove)
		{
			WE_CORE_INFO("\"" + (*it)->getName() + "\" which was child of \"" + getName() + "\" was removed");
			mChildren.erase(it);
			return;
		}

	WE_CORE_WARNING("\"" + nameOfObjectToRemove + "\" is not a child of \"" + getName() + "\" and could not be removed");
}

void GameObject::removeChild(GameObject* gameObjectToRemove)
{
	for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
		if (it->get() == gameObjectToRemove)
		{
			mChildren.erase(it);
			WE_CORE_INFO("\"" + (*it)->getName() + "\" which was child of \"" + mName + "\" was removed");
			return;
		}

	WE_CORE_WARNING("\"" + gameObjectToRemove->getName() + "\" is not a child of \"" + mName + "\" and could not be removed");
}

auto GameObject::getChild(const std::string& name) const -> GameObject&
{
	for (auto& child : mChildren)
		if (child->getName() == name)
			return *child.get();

	throw std::runtime_error("\"" + name + "\" is not a child of \"" + mName + "\" and could not be removed");
}

void GameObject::changeParentOfChild(GameObject* child, GameObject* newParent)
{
	for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
		if (it->get() == child)
		{
			newParent->addChild(std::move(*it));
			mChildren.erase(it);
			break;
		}

	WE_CORE_INFO("GameObject \"" + child->getName() + "\" became a child of the \"" + newParent->getName() + "\". It was a child of the \"" + mName + "\"");
}

}