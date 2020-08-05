#include "AssetManager.hpp"

namespace Med {
	void AssetManager::loadTexture(std::string name, std::string fileName) {
		sf::Texture tex;

		if (tex.loadFromFile(fileName)) {
			this->_textures[name] = tex;
		}
	}

	sf::Texture& AssetManager::getTexture(std::string name) {
		return this->_textures.at(name);
	}
	
	void AssetManager::loadMap(std::string name, Map map)
	{
			this->_maps[name] = map;
	}

	Map& AssetManager::getMap(std::string name)
	{
		return this->_maps.at(name);
	}

	void AssetManager::loadFont(std::string name, std::string fileName) {
		sf::Font f;

		if (f.loadFromFile(fileName)) {
			this->_fonts[name] = f;
		}
	}

	sf::Font& AssetManager::getFont(std::string name) {
		return this->_fonts.at(name);
	}

	void AssetManager::loadSoundBuffer(std::string name, std::string fileName) {
		sf::SoundBuffer sndb;

		if (sndb.loadFromFile(fileName)) {
			this->_soundBufferss[name] = sndb;
		}
	}

	sf::SoundBuffer& AssetManager::getSoundBuffer(std::string name) {
		return this->_soundBufferss.at(name);
	}

}