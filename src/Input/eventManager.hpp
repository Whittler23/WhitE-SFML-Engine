#pragma once

#include <SFML/Window.hpp>

namespace WhitE {

class EventManager
{
public:
	static bool getIsKeyPressed();
	static bool	getIsKeyReleased();
	static bool getIsButtonPressed();
	static bool getIsButtonReleased();

	static sf::Keyboard::Key getLastPressedKey();
	static sf::Keyboard::Key getLastReleasedKey();
	static sf::Mouse::Button getLastPressedButton();
	static sf::Mouse::Button getLastReleasedButton();

	static void setIsKeyPressed(const bool isKeyPressed);
	static void setIsKeyReleased(const bool isKeyReleased);
	static void setIsButtonPressed(const bool isButtonPressed);
	static void setIsButtonReleased(const bool isButtonReleased);

	static void setLastPressedKey(sf::Keyboard::Key key);
	static void setLastReleasedKey(sf::Keyboard::Key key);
	static void setLastPressedButton(sf::Mouse::Button button);
	static void setLastReleasedButton(sf::Mouse::Button button);

public:
	static void clear();

private:
	inline static bool mIsKeyPressed;
	inline static bool mIsKeyReleased;
	inline static bool mIsButtonPressed;
	inline static bool mIsButtonReleased;
	inline static sf::Keyboard::Key mLastPressedKey;
	inline static sf::Keyboard::Key mLastReleasedKey;
	inline static sf::Mouse::Button mLastPressedButton;
	inline static sf::Mouse::Button mLastReleasedButton;
};

}