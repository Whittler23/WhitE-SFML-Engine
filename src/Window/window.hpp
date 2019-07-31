#pragma once

#include <SFML/Graphics.hpp>

namespace WhitE {

enum class WindowStyle
{
	Fullscreen,
	Windowed
};

struct WindowProperties
{
	const std::string mGameWindowTitle;
	sf::Vector2u mGameWindowSize;
	WindowStyle mGameWindowStyle;

	WindowProperties(const std::string name, WindowStyle winStyle)
		:mGameWindowTitle(name)
		,mGameWindowStyle(winStyle)
	{}

	WindowProperties(const std::string name, WindowStyle winStyle, sf::Vector2u size)
		:mGameWindowTitle(name)
		,mGameWindowStyle(winStyle)
		,mGameWindowSize(size)
	{}
};

class Window
{
public:
	explicit Window(WindowProperties);

	auto getWindowWidth() const -> const unsigned { return mGameWindow.getSize().x; }
	auto getWindowHeight() const -> const unsigned { return mGameWindow.getSize().y; }

private:
	void initializeWindow();

private:
	sf::RenderWindow mGameWindow;
	WindowProperties mGameWindowProperties;

};

}