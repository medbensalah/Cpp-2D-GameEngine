#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace Med {
	class Animation {
	private:
		int indexX;
		int indexY;
		int frames;
		int tileSizeX;
		int tileSizeY;
		bool loopLast;
		bool finished = false;
		int left = 0;
		int delay = 0;
		int maxDelay;
		sf::Sprite sprite;
		sf::Texture tex;
	public:

		Animation() {}
		Animation(int iX,int iY, int f, int sizeX, int sizeY, float sc, int delay, bool loop, sf::Texture& t) {
			indexY = iY * sizeY;
			indexX = iX * sizeX;
			frames = f;
			maxDelay = delay;
			tileSizeX = sizeX;
			tileSizeY = sizeY;
			tex = t;
			sprite.setTexture(tex);
			sprite.setScale(sc,sc);
			loopLast = loop;
		}

		void init(int iX, int iY, int f, int sizeX, int sizeY, float sc, int delay, bool loop, sf::Texture& t) {
			indexY = iY * sizeY;
			indexX = iX * sizeX;
			frames = f;
			maxDelay = delay;
			tileSizeX = sizeX;
			tileSizeY = sizeY;
			tex = t;
			sprite.setTexture(tex);
			sprite.setScale(sc, sc);
			loopLast = loop;
			finished = false;

		}
		Animation(int iX,int iY, int f, int sizeX, int sizeY, float scX, float scY, int delay, bool loop, sf::Texture& t) {
			indexY = iY * sizeY;
			indexX = iX * sizeX;
			frames = f;
			maxDelay = delay;
			tileSizeX = sizeX;
			tileSizeY = sizeY;
			tex = t;
			sprite.setTexture(tex);
			sprite.setScale(scX,scY);
			loopLast = loop;
		}

		void init(int iX, int iY, int f, int sizeX, int sizeY, float scX, float scY, int delay, bool loop, sf::Texture& t) {
			indexY = iY * sizeY;
			indexX = iX * sizeX;
			frames = f;
			maxDelay = delay;
			tileSizeX = sizeX;
			tileSizeY = sizeY;
			tex = t;
			sprite.setTexture(tex);
			sprite.setScale(scX, scY);
			loopLast = loop;
			finished = false;

		}

		void setOrigin(float x, float y) {
			sprite.setOrigin(x, y);
		}

		void setMirror(bool mirror = true) {
			mirror ?
				sprite.setScale(-1.0f * abs(sprite.getScale().x), abs(sprite.getScale().y))
				:
				sprite.setScale(abs(sprite.getScale().x), abs(sprite.getScale().y));
		}

		void move(float x, float y) {
			sprite.move(x, y);
		}

		void setYIndex(int i, int sizeY) {
			indexY = i * sizeY;
		}
		
		void setXIndex(int i) {
			left = i;
			finished = false;
		}

		void setLoopLast(bool loop = true) {
			loopLast = loop;
		}

		void setPosition(int x, int y) {
			sprite.setPosition(x, y);
		}

		void setFrames(int f) {
			frames = f;
		}

		void update(float dt) {
			if(!loopLast)
				left = left % frames;
			else {
				if (left == frames - 1)
					finished = true;
				if (finished) {
					left = frames - 1;
				}
			}
			sprite.setTextureRect(sf::IntRect(left * tileSizeX, indexY, tileSizeX, tileSizeY));
			if(++delay % maxDelay == 0)
				left = left++;

		}

		sf::Sprite& getSprite() {
			return sprite;
		}
	};
}