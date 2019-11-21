#include "States/state.hpp"
#include "Gui/guiManager.hpp"
#include "sharedData.hpp"
#include "Gui/Widgets/button.hpp"
#include "Input/actionManager.hpp"

namespace WhitE {

class TestState : public State
{
public:
	TestState(SharedData& data)
		:State(data)
		, mGuiManager(data.mWindow.getRenderWindow(), data.mWindow.getRenderWindow().getView())
	{}

	void onPop() override
	{}

	void onPush() override
	{
		mGuiManager.addWidget("testWidget", std::make_unique<gui::Widget>());
		mGuiManager.addWidget("button", std::make_unique<gui::Button>());
		mGuiManager.get("button")->setPercentagePosition(sf::Vector2f(0.f, 0.f));
		mGuiManager.get("button")->setPercentageSize(sf::Vector2f(10.f, 5.f));
	}

	void draw() const override
	{	
		mGuiManager.draw();
	}

	void input() override
	{
		if (ActionManager::isActionPressed("changeSize"))
		{
			auto* widget = mGuiManager.get("button");
			auto position = widget->getPosition();
			widget->setPosition(position + sf::Vector2f(10.f, 10.f));
		}
		else if (ActionManager::isActionPressed("changeSizePercent"))
		{
			auto* widget = mGuiManager.get("button");
			auto position = widget->getPercentPosition();
			widget->setPercentagePosition(position + sf::Vector2f(1.f, 1.f));
		}
	}

	void update(const sf::Time& deltaTime) override
	{}

private:
	gui::GuiManager mGuiManager;
};

}
