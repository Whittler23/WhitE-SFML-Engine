#include "Resources/resourcesManager.hpp"
#include "Logger/logs.hpp"


template<typename ResourceType>
WhitE::ResourcesManager<typename ResourceType>::ResourcesManager()
{
}

template<typename ResourceType>
void WhitE::ResourcesManager<typename ResourceType>::load(const std::string& name, const std::string& resPath)
{
	auto resource = std::make_unique<ResourceType>();
	if (resource->loadFromFile(resPath))
	{
		mResourcesMap.insert(std::make_pair(name, std::make_pair(resPath, std::move(resource))));
		WE_CORE_INFO("Resource \"" + name + " with filepath \"" + resPath + "\" was loaded!");
	}
	else
		throw std::runtime_error("Could not find specified filepath \"" + resPath + "\"");
}

template<typename ResourceType>
auto WhitE::ResourcesManager<typename ResourceType>::get(const std::string& name) -> ResourceType&
{
	auto found = mResourcesMap.find(name);
	if (found != mResourcesMap.end())
		return *found->second.second;
	else
		throw std::runtime_error("Could not find specified resource \"" + name + "\"");
}

template<typename ResourceType>
void WhitE::ResourcesManager<typename ResourceType>::free(const std::string& name)
{
	auto found = mResourcesMap.find(name);
	if (found != mResourcesMap.end())
	{
		WE_CORE_INFO("Resource \"" + name + "\" with filepath " + " was erased!");
		mResourcesMap.erase(found);
	}
	else
		throw std::runtime_error("Could not find specified resource \"" + name + "\"");
}

template<typename ResourceType>
bool WhitE::ResourcesManager<typename ResourceType>::doesExist(const std::string& name)
{
	return mResourcesMap.count(name) ? true : false;
}
