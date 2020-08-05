#include "IntroductionFMVState.hpp"
#include "WorldState.hpp"
#include <sstream>
#include <Windows.h>
#include <iostream>

namespace Med {
	IntroductionFMVState::IntroductionFMVState(GameDataRef data) : _data(data) {}


	void IntroductionFMVState::init() {
		this->_data->assets.loadTexture("Intro City", INTRO_SCENE_CITY);
		this->_data->assets.loadTexture("Intro Room", INTRO_SCENE_ROOM);
		this->_data->assets.loadTexture("Black Shade", BLACK_PATH);
		this->_data->assets.loadTexture("White", WHITE_PATH);

		_roomSND.setBuffer(this->_data->assets.getSoundBuffer("Click"));

		_white.setTexture(this->_data->assets.getTexture("White"));
		_white.setColor(sf::Color(255, 255, 255, 0));
		_black.setTexture(this->_data->assets.getTexture("Black Shade"));
		_black.setColor(sf::Color(0, 0, 0, 0));
		_city.setTexture(this->_data->assets.getTexture("Intro City"));
		_city.setTextureRect(sf::IntRect(0, 0, 1280, 663));

		this->_room = new Animation(0, 0, 12, 1280, 663, 1, 6, false, this->_data->assets.getTexture("Intro Room"));

		this->_data->assets._bgm.openFromFile(INTRO_SCEN_BGM);
		this->_data->assets._bgm.play();

		this->_clock.restart();
	}

	void IntroductionFMVState::handleInput() {
		sf::Event e;

		while (this->_data->window.pollEvent(e)) {
			if (sf::Event::Closed == e.type) {
				this->_data->window.close();
			}
		}
	}

	int roomIndex = 0;
	int roomFrames = 6;
	int roomCurrentFrame = 0;


	void IntroductionFMVState::update(float dt) {
		if (static_cast<int>(this->_clock.getElapsedTime().asMilliseconds()) - cl > 40 && !shade) {
			if (alpha > 15) {
				alpha -= 20;
				sf::Color black(0, 0, 0, alpha);
				_black.setColor(black);
			}
			else if (alpha == 15) {
				alpha = 0;
				sf::Color black(0, 0, 0, alpha);
				_black.setColor(black);
				this->_data->window.draw(this->_black);
				shade = 1;
			}
			cl = static_cast<int>(this->_clock.getElapsedTime().asMilliseconds());
		}

		if (shade == 1) {
			if (_city.getTextureRect().left <= 1280) {
				_city.setTextureRect(sf::IntRect(_city.getTextureRect().left + 3, 0, 1280, 663));
			}
			if (_city.getTextureRect().left >= 1100) {
				cityFinished = true;
			}
		}

		if (static_cast<int>(this->_clock.getElapsedTime().asMilliseconds()) - cl > 20 && cityFinished && shade == 1) {
			if (alpha < 240) {
				alpha += 20;
				sf::Color black(0, 0, 0, alpha);
				_black.setColor(black);
				cl = static_cast<int>(this->_clock.getElapsedTime().asMilliseconds());
			}
			else if (alpha == 240) {
				alpha = 255;
				sf::Color black(0, 0, 0, alpha);
				_black.setColor(black);
				this->_data->window.draw(this->_black);
				cl = static_cast<int>(this->_clock.getElapsedTime().asMilliseconds());
			}
			else if (alpha == 255) {
				shade = 2;
				_clock.restart();
				cl = 0;
				this->_data->assets._bgm.stop();
			}
		}

		if (shade == 2) {
			_roomSND.play();
			if (_room->getSprite().getTextureRect().left == 14080) {
				shade = 3;
			}
			_room->update(dt);
		}

		if (static_cast<int>(this->_clock.getElapsedTime().asMilliseconds()) - cl > 40 && shade == 3) {
			if (alpha > 15) {
				alpha -= 20;
				_white.setColor(sf::Color(255, 255, 255, alpha));
			}
			else if (alpha == 15) {
				alpha = 0;
				_white.setColor(sf::Color(255, 255, 255, alpha));
			}
			cl = static_cast<int>(this->_clock.getElapsedTime().asMilliseconds());

			if (alpha == 0) {
				delete _room;
				this->_data->assets.clearTex();
				Sleep(500);
				this->_data->machine.addState(StateRef(new WorldState(_data)), true);
			}

		}
	}

	void IntroductionFMVState::draw(float dt) {
		this->_data->window.clear(sf::Color::Black);

		if (alpha != 255 && shade <= 1)
			this->_data->window.draw(this->_city);
		//		if (alpha != 0)
		this->_data->window.draw(this->_black);
		if (shade == 2)
			this->_data->window.draw(this->_room->getSprite());
		this->_data->window.draw(this->_white);

		this->_data->window.display();
	}
}