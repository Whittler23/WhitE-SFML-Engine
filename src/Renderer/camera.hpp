#pragma once

#include <SFML/Graphics.hpp>

namespace WhitE {

class Camera
{
public:
	Camera();

	void update(const sf::Time deltaTime) {}

	void setView(const sf::Vector2f& view);

	auto getView() const -> const sf::View & { return mView; }

private:
	sf::View mView;

};

}