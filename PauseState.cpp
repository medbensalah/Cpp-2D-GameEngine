#include <sstream>
#include <Windows.h>
#include <iostream>
#include "PauseState.hpp"


extern Med::Coordinator coordinator;
extern std::shared_ptr<Med::PlayerSystem> playerSystem;


namespace Med {
	PauseState::PauseState(GameDataRef data) : _data(data) {}

	void PauseState::init() {
		//Components

		//systems


		//entity

		//entities add component

		//System init

		_data->assets.loadTexture("pauseBackground", PAUSE_MENU_BACKGROUND);
		_data->assets.loadTexture("pauseBackground0", PAUSE_MENU_BACKGROUNDI);
		_data->assets.loadTexture("pauseMenuItem", PAUSE_MENU_ITEM);
		
		_background.setTexture(this->_data->assets.getTexture("pauseBackground"));
		_backgroundI.setTexture(this->_data->assets.getTexture("pauseBackground0"));
		_data->assets.getTexture("pauseMenuItem").setSmooth(true);
		_bits.setTexture(this->_data->assets.getTexture("pauseMenuItem"));
		for (auto& kv : _menuItems) {
			kv.second.setTexture(this->_data->assets.getTexture("pauseMenuItem"));
			kv.second.setScale(1, 1.7f);
			kv.second.setOrigin(0, 10);
		}
		_menuItems[0].setPosition(playerSystem->tc->position.x - 600 * 0.85f + 725, playerSystem->tc->position.y - 300 * 1.7f + 125 * 1.7f);
		_menuItems[1].setPosition(playerSystem->tc->position.x - 600 * 0.85f + 705, playerSystem->tc->position.y - 300 * 1.7f + 175 * 1.7f);
		_menuItems[2].setPosition(playerSystem->tc->position.x - 600 * 0.85f + 692, playerSystem->tc->position.y - 300 * 1.7f + 225 * 1.7f);
		_menuItems[3].setPosition(playerSystem->tc->position.x - 600 * 0.85f + 685, playerSystem->tc->position.y - 300 * 1.7f + 275 * 1.7f);
		_menuItems[4].setPosition(playerSystem->tc->position.x - 600 * 0.85f + 680, playerSystem->tc->position.y - 300 * 1.7f + 325 * 1.7f);
		_menuItems[5].setPosition(playerSystem->tc->position.x - 600 * 0.85f + 685, playerSystem->tc->position.y - 300 * 1.7f + 375 * 1.7f);
		_menuItems[6].setPosition(playerSystem->tc->position.x - 600 * 0.85f + 692, playerSystem->tc->position.y - 300 * 1.7f + 425 * 1.7f);
		_menuItems[7].setPosition(playerSystem->tc->position.x - 600 * 0.85f + 705, playerSystem->tc->position.y - 300 * 1.7f + 475 * 1.7f);
		_menuItems[8].setPosition(playerSystem->tc->position.x - 600 * 0.85f + 725, playerSystem->tc->position.y - 300 * 1.7f + 525 * 1.7f);
		_background.setPosition(playerSystem->tc->position.x - 600 * 0.85f, playerSystem->tc->position.y - 300 * 1.7f);
		_background.setScale(0.85f, 1.7f);
		_backgroundI.setPosition(playerSystem->tc->position.x - 600 * 0.85f, playerSystem->tc->position.y - 300 * 1.7f);
		_backgroundI.setScale(0.85f, 1.7f);
		_bits.setScale(1, 1.7f);
		_bits.setTextureRect(sf::IntRect(0, 40, 256, 40));
		_bits.setPosition(playerSystem->tc->position.x - 600 * 0.85f + 30, playerSystem->tc->position.y - 300 * 1.7f + 900);
		_shownItems = -1;
		_shown = 0;
		_selected = 0;

		/*
		this->_data->assets._bgm.stop();

		this->_data->assets._bgm.openFromFile(LOGIN_BGM);
		this->_data->assets._bgm.setLoop(true);
		this->_data->assets._bgm.play();
		*/
	}

	void PauseState::handleInput() {
		sf::Event e;

		while (this->_data->window.pollEvent(e)) {
			if (sf::Event::Closed == e.type) {
				this->_data->window.close();
			}
			if (e.type == sf::Event::KeyPressed) {
				switch (e.key.code)
				{
				case sf::Keyboard::X:
					this->_data->machine.removeState();
					break;
				case sf::Keyboard::Up:
					_selected = (_selected + 8) % 9;
					break;
				case sf::Keyboard::Down:
					_selected = (_selected + 1) % 9;
					break;
				default:
					break;
				}
			}
		}
	}

	void PauseState::update(float dt) {
		if (_shown != 663) {
			_shown < 663 ? _shown += 26/1.7f : _shown = 663;
			_background.setTextureRect(sf::IntRect(0, 0, 1200, _shown));
		}
		for (auto& kv : _menuItems) {			
			_selected == kv.first ?	kv.second.setTextureRect(sf::IntRect(0, 40, 256, 40)) : kv.second.setTextureRect(sf::IntRect(0, 0, 256, 40));
		}
	}

	void PauseState::draw(float dt) {
		this->_data->window.clear(sf::Color::Black);

		_data->assets.getMap("1").draw(_data->window);
		playerSystem->draw(_data->window);
		this->_data->window.draw(_backgroundI);
		this->_data->window.draw(_background);
		for (auto& kv : _menuItems) {
			if (_shownItems >= kv.first)
				_data->window.draw(kv.second);
		}
		_data->window.draw(_bits);

		if (_shownItems < 8) 
			_shownItems++;

		this->_data->window.display();
	}
}