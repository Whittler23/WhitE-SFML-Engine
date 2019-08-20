#pragma once

#include <SFML/Graphics.hpp>

namespace WhitE {

struct WindowProperties
{
	const std::string mWinTitle;
	sf::Vector2u mWinSize;
	bool mWinFllscr;

	WindowProperties()
		:mWinTitle("WhitE")
		,mWinFllscr(false)
		,mWinSize(640, 480)
	{}

	WindowProperties(const std::string name, bool winStyle, sf::Vector2u size = { 0, 0 })
		:mWinTitle(name)
		,mWinFllscr(winStyle)
		,mWinSize(size)
	{}
};

class Window
{
public:
	Window(const std::string name, bool winStyle, sf::Vector2u size);
	Window();

	void update();
	void draw(sf::Drawable& drawable);
	void input();

	auto getRenderWindow() -> sf::RenderWindow & { return mGameWindow; }
	auto getWindowWidth() const -> const unsigned { return mGameWindow.getSize().x; }
	auto getWindowHeight() const -> const unsigned { return mGameWindow.getSize().y; }
	bool shouldClose() { return mShouldClose; }

private:
	void initializeWindow();

private:
	sf::RenderWindow mGameWindow;
	WindowProperties mProperties;
	bool mShouldClose;

};

}