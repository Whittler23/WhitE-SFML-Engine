#pragma once

#include "Resources/resourcesManager.hpp"

#include "Resources/resourcesManager.inl"

#include <SFML/Audio.hpp>

namespace WhitE {

class ResourceHolder
{
public:
	ResourceHolder();

	auto getTextureHolder()  ->  ResourcesManager<sf::Texture>& { return mTextureHolder; }
	auto getSoundHolder()  ->  ResourcesManager<sf::SoundBuffer>& { return mSoundHolder; }
	auto getFontHolder()  ->  ResourcesManager<sf::Font>& { return mFontHolder; }

private:
	ResourcesManager<sf::Texture> mTextureHolder;
	ResourcesManager<sf::SoundBuffer> mSoundHolder;
	ResourcesManager<sf::Font> mFontHolder;

};


}
