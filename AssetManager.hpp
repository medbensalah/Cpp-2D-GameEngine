#pragma once

#include <map>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Animation.hpp"
#include "Map.hpp"

namespace Med {
	class AssetManager {
	public:
		AssetManager() {}
		~AssetManager() {}

		void loadTexture(std::string name, std::string fileName);
		sf::Texture& getTexture(std::string name);

		void loadMap(std::string name, Map map);
		Map& getMap(std::string name);

		void loadFont(std::string name, std::string fileName);
		sf::Font& getFont(std::string name);

		void loadSoundBuffer(std::string name, std::string fileName);
		sf::SoundBuffer& getSoundBuffer(std::string name);

		void clearTex() {
			_textures.clear();
		}

		sf::Music _bgm;

	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, Map> _maps;
		std::map<std::string, sf::Font> _fonts;
		std::map<std::string, sf::SoundBuffer> _soundBufferss;
	};
}