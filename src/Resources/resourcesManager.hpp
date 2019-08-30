#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <unordered_map>
#include <memory>

namespace WhitE {

	template<typename ResourceType >
class ResourcesManager
{
public:
	ResourcesManager();

	void load(const std::string& name, const std::string& filepath);
	void free(const std::string& name);
	auto get(const std::string& name) -> ResourceType&;
	bool doesExist(const std::string&);

private:
	std::unordered_map<std::string, std::pair<std::string, std::unique_ptr<ResourceType> > > mResourcesMap;
	
};

}
