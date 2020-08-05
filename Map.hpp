#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>
#include "ECS.hpp"
#include "DEFINITIONS.hpp"

extern Med::Coordinator  coordinator;

namespace Med {
	class Map {
	public:
		Map(float scale, int s, int tileSize, std::string path, sf::Texture& tex, bool fight = false);
		Map();
		~Map() {}

		void loadFromPath(sf::Texture& tex);
		void addTile(int x, int y, int posX, int posY, char d, sf::Texture& tex);
		void draw(sf::RenderWindow& window);
	private:
		int size;
		int tileSize;
		double scale;
		bool fight;
		std::string path;
		std::map<int, sf::Sprite> _tiles;
		std::map<int, sf::ConvexShape> _colliders;
		std::map<int, sf::ConvexShape> _zones;
	};
}