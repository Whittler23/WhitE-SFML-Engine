#include "Resources/resourcesManager.hpp"


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
	else;
		//TODO:	Warning Log
}

template<typename ResourceType>
void WhitE::ResourcesManager<typename ResourceType>::free(const std::string& resPath)
{
	auto found = mResourcesMap.find(resPath);
	if (found != mResourcesMap.end())
		mResourcesMap.erase(found);
	else;
		//TODO: Warning Log
}

template<typename ResourceType>
void WhitE::ResourcesManager<typename ResourceType>::load(const std::string& resPath)
{
	//ResourceType resource;
	auto resource = std::make_unique<ResourceType>();
	if (resource->loadFromFile(resPath))
		mResourcesMap.insert(std::make_pair(resPath, std::move(resource)));
	else;
		//TODO: Warning Log
}

template<typename ResourceType>
bool WhitE::ResourcesManager<typename ResourceType>::doesExist(const std::string& resPath)
{
	return mResourcesMap.count(resPath) ? true : false;
}
