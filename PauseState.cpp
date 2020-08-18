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
				if (e.key.code == sf::Keyboard::X) {

				}
			}
		}
	}

	void PauseState::update(float dt) {

	}

	void PauseState::draw(float dt) {
		this->_data->window.clear(sf::Color::Black);

		_data->assets.getMap("1").draw(_data->window);
		playerSystem->draw(_data->window);
		//	collisionSystem->draw(_data->window);

		this->_data->window.display();
	}
}