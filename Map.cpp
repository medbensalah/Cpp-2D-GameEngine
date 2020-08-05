#include "Map.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

extern Med::Coordinator coordinator;

namespace Med {
	Map::Map(float sc, int s, int tileSize, std::string path, sf::Texture& tex, bool fight) {
		scale = sc;
		size = s;
		this->tileSize = tileSize;
		this->path = path;
		this->fight = fight;
		loadFromPath(tex);
		
	}

	Map::Map() {}

	void Map::addTile(int x, int y, int posX, int posY, char d, sf::Texture& tex) {
		Entity tile = coordinator.CreateEntity();
		sf::Sprite spr;
		spr.setTexture(tex);
		spr.setTextureRect(sf::IntRect(x * tileSize, y * tileSize / 2, tileSize, tileSize / 2));
		spr.setPosition(posX + 620 , posY);
		spr.setScale(scale, scale);
		_tiles.emplace(tile, spr);
		if (atoi(&d)) {
			sf::ConvexShape pol(4);
			pol.setPosition(spr.getPosition());
			pol.setPoint(0, sf::Vector2f(tileSize * scale / 2, 0));
			pol.setPoint(1, sf::Vector2f(0, tileSize * scale / 4));
			pol.setPoint(2, sf::Vector2f(tileSize * scale / 2, tileSize * scale / 2));
			pol.setPoint(3, sf::Vector2f(tileSize * scale, tileSize * scale / 4));
			coordinator.AddComponent(tile, ColliderComponent{
				pol
			});
			if (fight) {
				coordinator.AddComponent(tile, GridComponent{
				posX,
				posY,
				size,
				0
			});
				pol.setFillColor(sf::Color(240, 57, 29, 100));
				pol.setOutlineColor(sf::Color::White);
				pol.setOutlineThickness(1);
				_colliders.emplace(tile, pol);
			}
		}
		if(fight && !atoi(&d)) {
			coordinator.AddComponent(tile, GridComponent{
				posX,
				posY,
				size,
				1
			});
			sf::ConvexShape pol(4);
			pol.setPosition(spr.getPosition());
			pol.setPoint(0, sf::Vector2f(tileSize * scale / 2, 0));
			pol.setPoint(1, sf::Vector2f(0, tileSize * scale / 4));
			pol.setPoint(2, sf::Vector2f(tileSize * scale / 2, tileSize * scale / 2));
			pol.setPoint(3, sf::Vector2f(tileSize * scale, tileSize * scale / 4));
			pol.setFillColor(sf::Color::Transparent);
			pol.setOutlineColor(sf::Color::White);
			pol.setOutlineThickness(1);
			_zones.emplace(tile, pol);
		}
	}
		
	void Map::draw(sf::RenderWindow& window) {
		
		for (auto kv : _tiles) {
			window.draw(kv.second);
		}

		if (fight) {
			for (auto kv : _colliders) {
				window.draw(kv.second);
			}
			for (auto kv : _zones) {
				window.draw(kv.second);
			}
		}
	}

	void Map::loadFromPath(sf::Texture& tex) {
		char c = '0';
		char d = '0';
		std::fstream mapFile;
		std::fstream mapColFile;

		int tilex, tiley;
		int targetX, targetY;
		mapFile.open(path + ".map");

		mapColFile.open(path + " col.map");
		for(int i = 0; i < size; i++){
			for (int j = 0; j < size; j++) {

				int pos = 0;
				do {
					pos = pos * 10 + atoi(&c);
					tilex = pos % 10;
					tiley = pos / 10;
					targetX = (j - i) * scale * tileSize / 2;
					targetY = (j + i) * scale * tileSize / 4;
					mapFile.get(c);
				} while (c <= '9' && c >= '0');
				mapColFile.get(d);
				mapColFile.ignore();

				addTile(tilex, tiley, targetX, targetY, d, tex);

			}
		}
		mapFile.close();
		mapColFile.close();

	}
}