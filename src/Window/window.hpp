#pragma once

#include <SFML/Graphics.hpp>

namespace WhitE {

struct WindowProperties
{
	const std::string mWindowTitle;
	sf::Vector2u mWinSize;
	bool mWinFullscreen;

	WindowProperties()
		:mWindowTitle("WhitE")
		,mWinFullscreen(false)
		,mWinSize(640, 480)
	{}

	WindowProperties(const std::string name, bool winStyle, sf::Vector2u size = { 0, 0 })
		:mWindowTitle(name)
		,mWinFullscreen(winStyle)
		,mWinSize(size)
	{}
};

class Window
{
public:
	Window(WindowProperties);
	Window();

	void update();
	void draw();

	auto getWindowWidth() const -> const unsigned { return mGameWindow.getSize().x; }
	auto getWindowHeight() const -> const unsigned { return mGameWindow.getSize().y; }
	bool isOpen() const { return mGameWindow.isOpen(); }

private:
	void initializeWindow();

private:
	sf::RenderWindow mGameWindow;
	WindowProperties mProperties;

};

}