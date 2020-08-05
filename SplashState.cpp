#include <sstream>
#include <Windows.h>
#include <iostream>
#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include "WorldState.hpp"

namespace Med {
	SplashState::SplashState(GameDataRef data) : _data(data) {}


	void SplashState::init() {
		this->_data->assets.loadTexture("Splash State Background", SPLASH_SCENE8_BACKGROUND_FILEPATH);
		this->_data->assets.loadTexture("Black Shade", BLACK_PATH);

		_background.setTexture(this->_data->assets.getTexture("Splash State Background"));
		_black.setTexture(this->_data->assets.getTexture("Black Shade"));
	}

	void SplashState::handleInput() {
		sf::Event e;

		while (this->_data->window.pollEvent(e)) {
			if (sf::Event::Closed == e.type) {
				this->_data->window.close();
			}
		}
	}

	int cl = 1100;
	int alpha = 255;

	bool shade = false;

	void SplashState::update(float dt) {
		if (static_cast<int>(this->_clock.getElapsedTime().asMilliseconds()) - cl > 20 && !shade) {
			if (alpha > 15) {
				alpha -= 20;
				sf::Color black(0, 0, 0, alpha);
				_black.setColor(black);
			}
			else if (alpha <= 15) {
				alpha = 0;
				shade = true;
				sf::Color black(0, 0, 0, alpha);
				_black.setColor(black);
			}
			cl = static_cast<int>(this->_clock.getElapsedTime().asMilliseconds());
		}
		else if (static_cast<int>(this->_clock.getElapsedTime().asMilliseconds()) - cl > 20) {
			if (alpha < 240) {
				alpha += 20;
				sf::Color black(0, 0, 0, alpha);
				_black.setColor(black);
			}
			else if (alpha >= 240) {
				alpha = 255;
				sf::Color black(0, 0, 0, alpha);
				_black.setColor(black);
				this->_data->window.draw(this->_black);
				if (this->_clock.getElapsedTime().asMilliseconds() > SPLASH_STATE_SHOW_TIME) {
		//			this->_data->machine.addState(StateRef(new MainMenuState(_data)), true);
					this->_data->machine.addState(StateRef(new WorldState(_data)), true);
				}
			}
			cl = static_cast<int>(this->_clock.getElapsedTime().asMilliseconds());
		}
	}

	void SplashState::draw(float dt) {
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_black);

		this->_data->window.display();
		

		if (this->_clock.getElapsedTime().asMilliseconds() > SPLASH_STATE_SHOW_TIME) {
			//			this->_data->machine.addState(StateRef(new MainMenuState(_data)), true);
			this->_data->machine.addState(StateRef(new WorldState(_data)), true);
		}

		if (alpha == 0) {
			Sleep(1000);
		}
		if (alpha == 255) {
			Sleep(500);
		}
	}
}