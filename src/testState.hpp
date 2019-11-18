#include "States/state.hpp"
#include "Gui/guiManager.hpp"
#include "sharedData.hpp"

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
	}

	void draw() const override
	{
		sf::RectangleShape rect({ 400.f, 200.f });
		rect.setFillColor(sf::Color::Blue);
		rect.setPosition({ 700.f, 300.f });
		getSharedData().mWindow.getRenderWindow().draw(rect);
		mGuiManager.draw();
	}

	void input() override
	{

	}

	void update(const sf::Time& deltaTime) override
	{}

private:
	gui::GuiManager mGuiManager;
};

}
