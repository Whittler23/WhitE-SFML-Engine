#pragma once

#include "Renderer/layer.hpp"

#include <SFML/Graphics.hpp>

#include <unordered_map>

namespace WhitE {

	class DrawableGameObject;
	class GameEngineObject;
	class GuiElement;

	class StateRenderer
	{
	public:
		StateRenderer(sf::RenderTarget& renderTarget);
		~StateRenderer();

		void init();

		void attachGui(std::list<std::unique_ptr<GuiElement>>* gui);
		void removeGui();

		void draw() const;

		void addObjectToDrawables(LayerType layerType, DrawableGameObject* const object);

		void removeObjectFromDrawables(LayerType layerType, DrawableGameObject* const object);
		void removeObjectFromDrawables(LayerType layerType, const std::string& objectName);
		void removeObjectFromDrawables(const std::string& objectName);

		std::string getLayerName(LayerType layerType);

		void clearDrawables(LayerType layerType);
		void clearDrawables();

	private:
		void drawGui() const;

	private:
		sf::RenderTarget& mRenderTarget;
		std::list<std::unique_ptr<GuiElement>>* mGui;
		std::unordered_map<LayerType, Layer> mLayers;
		std::unordered_map<LayerType, std::string> mLayerNames;
	};

}
