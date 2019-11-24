#include <string>

namespace WhitE::gui {

template<typename T>
T* GuiManager::createWidget(const std::string& widgetName)
{
	std::unique_ptr<T> widget = std::make_unique<T>();
	T* widgetPtr = widget.get();
	mGuiContainer.addWidget(widgetName, std::move(widget));
	return widget.get();
}

}