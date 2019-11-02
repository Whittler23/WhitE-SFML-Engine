#pragma once

#include <unordered_map>
#include <string>
#include <memory>

namespace WhitE {

class Widget;

class GuiManager
{
public:
	GuiManager();

	void addContainer(const std::string& containerName, std::unique_ptr<Widget> newContainer);

	Widget* get(const std::string& containerName);
	Widget* get(const Widget& container);
	std::vector<std::unique_ptr<Widget>>& getContainers();

	void remove(const std::string& containerName);
	void remove(const Widget& container);
	void removeAllContainers();

	std::string getContainerName();
	std::vector<std::string> getContainerNames();

private:
	std::unordered_map<std::string, std::unique_ptr<Widget>> mContainersMap;
};

}