#pragma once

#include "Renderer/layer.hpp"
#include "Renderer/camera.hpp"

#include <SFML/Graphics.hpp>

#include <unordered_map>

namespace WhitE {

class GameEngineObject;

class Renderer
{
public:
	Renderer(sf::RenderTarget& renderTarget);
	~Renderer();

	void draw() const;
	void drawGameEngineObjects() const;

	void addGameEngineObject(GameEngineObject* const gameEngineObject);
	void removeGameEngineObject(const std::string& gameEngineObject);

	void update(const sf::Time deltaTime);

	void clearDrawableGameEngineObjects();

	auto getCamera() -> Camera& { return mCamera; }

private:
	sf::RenderTarget& mRenderTarget;
	std::list<GameEngineObject*> mGameEngineObjects;
	Camera mCamera;
};

}
