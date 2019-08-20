#include "Resources/resourcesManager.hpp"
#include "Logger/logs.hpp"


template<typename ResourceType>
WhitE::ResourcesManager<typename ResourceType>::ResourcesManager()
{
}

template<typename ResourceType>
auto WhitE::ResourcesManager<typename ResourceType>::get(const std::string& resPath) -> ResourceType&
{
	auto found = mResourcesMap.find(resPath);
	if (found != mResourcesMap.end())
		return *found->second;
	else
		WE_CORE_WARNING("Could not find specified path (" + resPath + ")");
}

template<typename ResourceType>
void WhitE::ResourcesManager<typename ResourceType>::free(const std::string& resPath)
{
	auto found = mResourcesMap.find(resPath);
	if (found != mResourcesMap.end())
	{
		mResourcesMap.erase(found);
		WE_CORE_INFO(resPath + " was erased!");
	}
	else
		WE_CORE_WARNING("Could not find specified path (" + resPath + ")");
}

template<typename ResourceType>
void WhitE::ResourcesManager<typename ResourceType>::load(const std::string& resPath)
{
	auto resource = std::make_unique<ResourceType>();
	if (resource->loadFromFile(resPath))
	{
		mResourcesMap.insert(std::make_pair(resPath, std::move(resource)));
		WE_CORE_INFO(resPath + " was loaded!");
	}
	else
		WE_CORE_WARNING("Could not find specified path (" + resPath + ")");
}

template<typename ResourceType>
bool WhitE::ResourcesManager<typename ResourceType>::doesExist(const std::string& resPath)
{
	return mResourcesMap.count(resPath) ? true : false;
}
