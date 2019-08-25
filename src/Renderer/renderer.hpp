#pragma once

#include "Renderer/layer.hpp"

#include <SFML/Graphics.hpp>

#include <unordered_map>

namespace WhitE {

class DrawableGameObject;
class GameEngineObject;

class Renderer
{
public:
	Renderer(sf::RenderTarget& renderTarget);
	~Renderer();

	void init();

	void draw() const;
	void drawGameEngineObjects() const;

	void addObjectToDrawables(LayerType layerType, DrawableGameObject* const object);
	void addGameEngineObject(GameEngineObject* const gameEngineObject);

	void removeObjectFromDrawables(LayerType layerType, DrawableGameObject* const object);
	void removeObjectFromDrawables(LayerType layerType, const std::string& objectName);
	void removeObjectFromDrawables(const std::string& objectName);
	void removeGameEngineObject(const std::string& gameEngineObject);

	std::string getLayerName(LayerType layerType);

	void clearDrawables(LayerType layerType);
	void clearDrawables();

private:
	sf::RenderTarget& mRenderTarget;
	std::unordered_map<LayerType, Layer> mLayers;
	std::unordered_map<LayerType, std::string> mLayerNames;
	std::list<GameEngineObject*> mGameEngineObjects;
};

}
